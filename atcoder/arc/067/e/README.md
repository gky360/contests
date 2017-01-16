# AtCoder Regular Contest 067

## [AC-][ARC067] E - Grouping

### 方針

dp。

dp[i][j] = (グループの人数が i 人以下で合計 j 人にする場合の数) とする。

$$
dp[0][0] = 1, \\
dp[i][j] = \sum_{k \in (0,C,C+1,...D)} dp[i - 1][j - i \cdot k] \cdot {}_{(n - j + i \cdot k)} P _{(i \cdot k)} / (i!)^k / k!
$$

で更新できる。

これだと O( N^3 ) に見えるが、k は必ず j / i 以下なので、計算量が落ちて O( N^2 log N ) となる。


### 計算量

O( N^2 log N )


### keywords

dp

