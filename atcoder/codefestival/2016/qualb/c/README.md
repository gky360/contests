# CODE FESTIVAL 2016 qual B

## [AC][CODEFESTIVAL2016 qualb] C - Gr-idian MST

### 方針

クラスカル法だけど、工夫して計算量を落とす必要がある。

$p_i$ と $q_i$ を一緒に昇順でソートして $\{costs_i\}$ とする。これを前から順番に見ていき、$costs_i$ の辺を追加できるだけ追加する。このとき、追加できる辺の本数は、

* $costs_i$ が x 方向の辺なら、H + 1 - (それまでに追加した y 方向の辺の本数)
* $costs_i$ が y 方向の辺なら、W + 1 - (それまでに追加した x 方向の辺の本数)

として求められる。


### 計算量

O( (W + H) log(W + H) )


### keywords

最小全域木, クラスカル法, kruskal
