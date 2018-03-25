# AGC019

## [AGC019] C - Fountain Walk

### 方針

LIS (Longest Increasing Sequence: 最長増加部分列) を求めることで解く。

x_1 < x_2, y_1 < y_2 として一般性を失わない。

始点から終点までに通る辺の数を `l` , 噴水を通る回数を `p` , そのうち180で曲がる回数を `q` とすると、移動距離は、

```
100 * l - (20 - 5 * PI) * p + 5 * PI * q
```

となる。

`l` の係数は `p` , `q` の係数に比べて十分に大きいので、まず `l` を最小化することを考えて構わない。 `100 * l` の最小値は、始点から終点までのマンハッタン距離である。

次に、 `p` を最大化することを考える。噴水を通ることのできる最大回数 `P` は、 (x_1, y_1), (x_2, y_2) の長方形に含まれる噴水について `a[x_i] = y_i` とした `a` の最長部分増加列の長さに等しい。

最後に、 `q` を最小化することを考える。実は、

```
q = 1 (P = min(x_2 - x_1, y_2 - y_1) + 1)
q = 0 (otherwise)
```

が成り立つ。（始点から終点に至るまでの全行 or 全列で噴水を通過した場合に、またその場合に限って、すべての噴水で90度曲がることはできず、ちょうど1回180度で曲がる必要があるため。）

以上のようにして、最小距離を求めることができる。


### 計算量

O( N log N )


### keywords

最長増加部分列, マンハッタン距離
