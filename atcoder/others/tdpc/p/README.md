# TDPC

## [TDPC] P - うなぎ

### 問題概要

与えられた木からK本の disjoint な path を選ぶ選び方を求める。

### 方針

木dp。木でのdpは必然的にdfsして分割統治法になることが多い。

```
dp[i][j][k] = (ノードiの部分木からj本のdisjointなpathを選び、かつiの次数がkとなるような選び方の総数)
```

として、dfsしながら部分木の答えを順次求めていく。pathがdisjointということは次数が必ず2以下になる、ということを利用するのがポイント。

各ノードの答えを求めるのにもう一つ別のdpが必要になるので、2段階のdpを計算することになる。

参考:  
http://suikaba.hatenablog.com/entry/2017/08/26/024334


### 計算量

O( N^2 K^2 )


### keywords

dp, 数え上げ, 木, disjoint
