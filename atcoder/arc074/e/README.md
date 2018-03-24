# AtCoder Regular Contest 074

## [AC-][ARC074] E - RGB Sequence

### 方針

dpで解く。

r, g, b をそれぞれ赤、緑、青の右端のますの位置とする。

`dp[r][g][b]` を、この状態から最後のマスまで塗る塗り方の数とすると、  
`dp[r][g][b] = dp[max(r, g, b) + 1][g][b] + dp[r][max(r, g, b) + 1][b] + dp[r][g][max(r, g, b) + 1]` である。

ただし、 `dp[r][g][b]` を更新するときに、r, g, b をもとにルールを満たすかどうか判定し、もし満たさなければ 0 とする。


### 計算量

O( N^3 + M * N^2 )


### keywords

dp, メモ化再帰


