# AtCoder Regular Contest 062

## [AC-][ARC062] E - AtCoDeerくんと立方体づくり / Building Cubes with AtCoDeer

### 方針

サイコロを置いたときの上の面と下の面の組を全探索する。

上の面と下の面が決まれば、すべての頂点の色が決まることになる。各組について、残りの4側面のパターンが何通りあるかを数えて足し合わせればいい。このとき、タイルを重複して使わないようにするのと、重複して数えたパターンをあとで除外することを忘れないようにする。

ちなみに、 `multiset::count` のオーダーが、 O( log N + (マッチする要素の数) ) 、つまりN個の要素がすべて同じだった場合に O(N) かかってしまうことを今知った。  
結局 vector に持たせて `upper_bound - lower_bound` で数える方針に変更した。


### 計算量

O( N )


### keywords

組み合わせ, 数え上げ, multiset, count, upper_bound, lower_bound

