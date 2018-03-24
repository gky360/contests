# AtCoder Regular Contest 075

## [AC-][ARC075] E - Meaningful Mean

### 方針

平均の式を書き換えることで、反転数の問題に帰結させる。

`[l, r)` の区間について、問題の条件を表す式は、

```
\sum_{i=l}^{r-1} a_i / (r - l) >= K

\sum_{i=0}^{r} a_i - r K >= \sum_{i=0}^{l} a_i - l K
```

と表せる。よって、 `b[n] = \sum_{i=0}^{n} a_i + n K` として、 `b[i] <= b[j], i < j` なる組の数を数える問題に帰結できる。以降、「平均」ということに関しては意識する必要がなくなる。

これは反転数を求める問題に当たる。 `b[i]` をソートしたときのindexをもちいることで0〜Nの範囲に圧縮できる。圧縮後の `b[i]` と Binary Indexed Tree を用いることで、反転数を数えることができる。


### 計算量

O( N log N )


### keywords

反転数, 平均, BIT


