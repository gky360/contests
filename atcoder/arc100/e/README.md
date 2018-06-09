# [ARC100] E - Or Plus Max

## 問題概要

長さ 2^N の 0-indexed な数列 A が与えられる。
1 <= K <= 2^N - 1 をみたすそれぞれの K について、
$$\max_{i, j} A_i + A_j $$ (ただし $$0 \le i < j \le 2^N - 1, i | j \le K$$ ) を求めよ。


## 方針

ゼータ変換なる言葉が解説に登場している。ゼータ変換とは、g(S)=「Sを部分集合として持つ全ての集合Tについてのf(T)の総和」を高速に求めるアルゴリズム。
$$
g(S) = \sum_{S \sube T} f(T)
$$
根底にある考えは bit DB で、 $S$ をサイズ1ずつ増やしながら $g$ を更新して行くことで高速に計算を行う。

また、ゼータ変換の逆変換はメビウス変換と呼ばれるらしい。 [高速ゼータ変換／高速メビウス変換 - naoya_t@hatenablog](http://naoyat.hatenablog.jp/entry/zeta-moebius) に分かりやすい解説がある。


## 計算量

O( N 2^N )


## keywords


bit DP, ゼータ変換, メビウス変換
