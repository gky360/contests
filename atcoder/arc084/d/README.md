
# [ARC084] D - Small Multiple

## 問題概要

K の正の倍数の 10 進法での各桁の和としてありうる最小の値を求める。


## 方針

グラフ。

自然数それぞれをノードと考える。以下の2種類の操作を有向辺と考える。

1. ある数に1を足す（各桁の和が1増える = コスト1）
2. ある数を10倍する（各桁の和は変わらない = コスト0）

1からスタートしてこの2種類の操作を繰り返すことによりすべての自然数を作ることができる。
求める答えは、1からKの倍数のうちのどれかまでの最短距離+1である。

ちなみに、操作 1. において1の位が9から繰り上がる場合であっても辺を張ってしまって構わない。なぜなら、繰り上がった後の数は操作 2. によってより少ないコストでたどり着くことができるので、最短距離に影響を与えないからである。

このままでは頂点数が無限になってしまうが、辺の張られ方から各自然数を mod K で同一視できることがわかる。これを用いると頂点数を K にできる。


## 計算量

頂点数 K のグラフ上での最短距離なので

O( log K )

ただし今回は 01BFS を用いることで O( K ) にできる。


## keywords

桁の和, グラフ, 最短距離, dijkstra, 01BFS
