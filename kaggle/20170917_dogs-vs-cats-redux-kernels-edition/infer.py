import argparse
import sys
import time

import numpy as np
import matplotlib.pyplot as plot

import chainer
import chainer.functions as F
from chainercv.datasets import voc_detection_label_names
from chainercv.links import SSD300
from chainercv.links import SSD512
from chainercv import utils
from chainercv.visualizations import vis_bbox
from chainercv.utils.iterator import apply_prediction_to_iterator

from dataset import Dataset


class ProgressHook(object):

    def __init__(self, n_total):
        self.n_total = n_total
        self.start = time.time()
        self.n_processed = 0

    def __call__(self, imgs, pred_values, gt_values):
        self.n_processed += len(imgs)
        fps = self.n_processed / (time.time() - self.start)
        sys.stdout.write(
            '\r{:d} of {:d} images, {:.2f} FPS'.format(
                self.n_processed, self.n_total, fps))
        sys.stdout.flush()


def predict_label(pred_label_list):
    cat_cnt = len(np.where(pred_label_list == Dataset.labels[0])[0])
    dog_cnt = len(np.where(pred_label_list == Dataset.labels[1])[0])
    if (cat_cnt > 0) != (dog_cnt > 0):
        pred_label = 0 if cat_cnt > 0 else 1
    else:
        print('random')
        pred_label = np.random.randint(2)
    return pred_label


def main():
    chainer.config.train = False

    parser = argparse.ArgumentParser()
    parser.add_argument(
        '--model', choices=('ssd300', 'ssd512'), default='ssd300')
    parser.add_argument('--split', choices=('train', 'test'), default='train')
    parser.add_argument('--gpu', type=int, default=-1)
    parser.add_argument('--batchsize', type=int, default=32)
    parser.add_argument('--pretrained_model', default='voc0712')
    args = parser.parse_args()

    if args.model == 'ssd300':
        model = SSD300(
            n_fg_class=len(voc_detection_label_names),
            pretrained_model=args.pretrained_model)
    elif args.model == 'ssd512':
        model = SSD512(
            n_fg_class=len(voc_detection_label_names),
            pretrained_model=args.pretrained_model)

    if args.gpu >= 0:
        chainer.cuda.get_device(args.gpu).use()
        model.to_gpu()

    train = Dataset()
    train_iter = chainer.iterators.MultiprocessIterator(
        train, args.batchsize, repeat=False, shuffle=False,
        n_processes=4, shared_mem=300000000)
    test = Dataset(split='test')
    test_iter = chainer.iterators.MultiprocessIterator(
        test, args.batchsize, repeat=False, shuffle=False,
        n_processes=4, shared_mem=300000000)

    print('Model has been prepared. Evaluation starts.')
    if args.split == 'train':
        iterator = train_iter
        hook = None
    else:
        iterator = test_iter
        hook = ProgressHook(len(test))
    imgs, pred_values, gt_values = apply_prediction_to_iterator(
        model.predict, iterator, hook=hook)
    del imgs

    pred_bboxes, pred_labels, pred_scores = pred_values
    gt_labels, = gt_values

    if args.split == 'train':
        for pred_label_list, gt_label, i in zip(
                pred_labels, gt_labels, range(len(train))):
            pred_label = predict_label(pred_label_list)
            res_txt = 'o' if pred_label == gt_label else 'x'
            print('{0:>5}: {1:>2} {2:>2} {3}'.format(
                i, pred_label, gt_label, res_txt))
    else:
        data = np.zeros((len(test), 2), dtype=np.int32)
        for pred_label_list, i in zip(pred_labels, range(len(test))):
            pred_label = predict_label(pred_label_list)
            data[i, 0] = i + 1
            data[i, 1] = pred_label
            np.savetxt('result/submission.csv', data[:(i + 1)],
                       delimiter=',', header='id,label', fmt='%d')


if __name__ == '__main__':
    main()
