# AtCoder Grand Contest 007

## [AC][AGC007] B - Construct Sequences

### 方針

まず、以下のように $\{a_i\}, \{b_i\}$ を初期化しておく。すると、 $a_{p_i} + b_{p_i}$ の値がすべて等しい状態となる。

$$
\begin{eqnarray}
(a_1 = 1) &<& (a_2 = 2    ) &<& \dots &<& (a_N = N) & \\
(b_1 = N) &>& (b_2 = N - 1) &<& \dots &<& (b_N = 1) & \\
\end{eqnarray}
\\
a_{p_1} + b_{p_1} = N + 1 \\
a_{p_2} + b_{p_2} = N + 1 \\
\dots \\
a_{p_N} + b_{p_N} = N + 1 \\
$$

この状態から、 `2 <= i <= N` の `i` それぞれについて、

* $a_{p_i}, a_{p_i+1}, \dots, a_N$ に `i - 1` を加える
* $b_1, b_2, \dots, b_{p_i}$ に `i - 1` を加える

という操作を行うことで、 $\{a_i\}, \{b_i\}$ それぞれの大小関係を保ちながら、 $a_{p_1} + b_{p_1} < a_{p_2} + b_{p_2} < \dots < a_{p_N} + b_{p_N}$ を満たすようにすることができる。

上記の各操作を O( log N ) で実現するためには、区間に一様に値を加えられる機能を追加した BIT を用いる。

### 計算量

O( N log N )

### keywords

BIT, LinearBIT, 区間に一様に値を加える

