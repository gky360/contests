import glob
import os

import chainer
from chainercv.datasets import voc_detection_label_names
from chainercv.utils import read_image


class Dataset(chainer.dataset.DatasetMixin):

    label_names = ['cat', 'dog']
    labels = list(map(
        lambda ln: voc_detection_label_names.index(ln), label_names))

    def __init__(self, split='train', data_dir='data'):
        super().__init__()
        self.train = (split == 'train')
        self.data_path = os.path.join(data_dir, split)
        self.file_pattern = '{}.{}.jpg' if self.train else '{}.jpg'
        file_paths = glob.glob(
            os.path.join(self.data_path, '*.jpg'))
        self.length = len(file_paths)

    def __len__(self):
        return self.length
        # return 4

    def get_example(self, i):
        label = -1

        if self.train:
            label_name = self.label_names[i % 2]
            label = i % 2
            img_name = self.file_pattern.format(label_name, i // 2)
        else:
            img_name = self.file_pattern.format(i + 1)
        img_path = os.path.join(self.data_path, img_name)
        img = read_image(img_path, color=True)

        return img, label
