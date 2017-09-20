import argparse
from datetime import datetime
import string
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


EPS = np.finfo(np.float32).eps

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


def predict_probability(pred_label_list):
    cat_cnt = len(np.where(pred_label_list == Dataset.labels[0])[0])
    dog_cnt = len(np.where(pred_label_list == Dataset.labels[1])[0])
    if cat_cnt == dog_cnt:
        print('not sure')
        pred_prob = 0.5
    elif cat_cnt > dog_cnt:
        # cat
        pred_prob = EPS
    else:
        # dog
        pred_prob = 1 - EPS
    return pred_prob


def main():
    chainer.config.train = False

    parser = argparse.ArgumentParser()
    parser.add_argument(
        '--model', choices=('ssd300', 'ssd512'), default='ssd300')
    parser.add_argument('--split', choices=('train', 'test'), default='train')
    parser.add_argument('--gpu', type=int, default=-1)
    parser.add_argument('--batchsize', type=int, default=16)
    parser.add_argument('--pretrained_model', default='voc0712')
    parser.add_argument('--begin', type=int, default=0)
    parser.add_argument('--end', type=int, default=-1)
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

    train = Dataset(begin=args.begin, end=args.end)
    train_iter = chainer.iterators.SerialIterator(
        train, args.batchsize, repeat=False, shuffle=False)
    test = Dataset(split='test', begin=args.begin, end=args.end)
    test_iter = chainer.iterators.SerialIterator(
        test, args.batchsize, repeat=False, shuffle=False)

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
            idx = i + test.begin
            pred_prob = predict_probability(pred_label_list)
            res_txt = 'o' if round(pred_prob) == gt_label else 'x'
            print('{0:>5}: {1:>2}\t{2:>2} {3}'.format(
                idx // 2, pred_prob, gt_label, res_txt))
    else:
        d_str = datetime.now().strftime('%Y%m%d%H%M%S')
        file_name = 'result/submission_{}_{:>5}_{:>5}.csv'.format(
            d_str, test.begin, test.end)
        data = np.zeros((len(test), 2))
        for pred_label_list, i in zip(pred_labels, range(len(test))):
            idx = i + test.begin
            pred_prob = predict_probability(pred_label_list)
            data[i, 0] = idx + 1
            data[i, 1] = pred_prob
            np.savetxt(file_name, data[:(i + 1)], delimiter=',',
                       header='id,label', fmt='%d')


if __name__ == '__main__':
    main()
