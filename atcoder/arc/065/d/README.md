# AtCoder Regular Contest 065

## [AC-][ARC065] 連結 / Connectivity

### 方針

UnionFind を2つ組み合わせる。

UnionFind を2つ用意して（`uf[0], uf[1]`）、組み合わせ `(uf[0].root(x), uf[1].root(x))` を管理することで実現する。


### 計算量

O( K + L + A(N) )


### keywords

UnionFind, グラフ


