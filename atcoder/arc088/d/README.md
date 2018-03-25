# AtCoder Regular Contest 088

## [ARC088] D - Wide Flip

### 方針

k 文字目と k + 1 文字目が異なっていた時、そこを境にした反転を1回以上必ず行わなければならない。この反転の長さの最大値は、 $\max(k, n - k)$ である。 $T(S) = \min_{k} \max(k, n - k)$ とおくと、 $T(S)$ は K の上界となる。

$T(S)$ の最小値を実現する $k$ を境に長さ $max(k, n - k)$ の反転を行うと、 $T(S)$ を減少させることなく連続した文字が異なる箇所の数を1減らすことができる。これを繰り返すことで目的の文字列をつくることかできる。

したがって、答えは最初の文字列 $S$ に対する $T(S)$ となる。


### 計算量

O( N )


### keywords

最小値の最大化