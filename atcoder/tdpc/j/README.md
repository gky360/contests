# TDPC

## [TDPC] J - ボール

### 方針

bit dp。

- b の i ビット目が 0 -> x_i のものが倒れている
- b の i ビット目が 1 -> x_i のものが倒れていない

として状態を表現する。

`b = 01100` のとき、座標1にボールを投げるとしたときの期待値 `E_1[b]` は、

```
E_1[01100] = (E[01100] + E[00100] + E[01000]) / 3 + 1
```

移項して、

```
E_1[01100] = (E[00100] + E[01000] + 3) / 2
```

となる。これを一般化して x = [1, N - 1) をそれぞれ考えると、dpの遷移は、

```
E[b] = \min_{x} ((s + 3.0) / c)
```

ただし、 `s = (座標[x-1, x+1]のうち立っているものを1つ倒した期待値の総和)` 、 `c = (座標[x-1, x+1]のうち立っているものの個数)` である。c = 0 の場合は投げても意味が無いのでスキップする。

今回はメモ化再帰で実装した。


### 計算量

O( 2^N )


### keywords

bit dp, 期待値, メモ化再帰
