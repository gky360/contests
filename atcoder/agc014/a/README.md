# AtCoder Grand Contest 014

## [AC][AGC014] A - Cookie Exchanges

### 方針

最大で log_2 max(A, B, C) 回繰り返せば良い。

最初、 A <= B <= C として一般性を失わない。この時、3つのうちの最大と最小の差は C - A である。

1回操作したとき、それぞれ、 (B + C) / 2, (C + A) / 2, (A + B) / 2 となるので、最大と最小の差は (C - A) / 2 となる。
よって、log_2 max(A, B, C) 回繰り返せば3つの数の差がなくなり、それ以上繰り返す意味がなくなる。


### 計算量

O( log max (A, B, C) )
