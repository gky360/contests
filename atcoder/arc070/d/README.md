# AtCoder Regular Contest 070

## [AC-][ARC070] D - No Need

### 方針

K の最大値の制限が小さいことから、ナップサック問題っぽいアルゴリズムなのでは？と気づく。

カード i が必要 = 「カードiを使わずに総和が K - a_i 以上 K 未満となる部分集合を作れる」である。これを、カード1枚ごとにナップサック問題のアルゴリズムを使って調べると、 O(K N^2) となり、部分点解法となる。

さらに計算量を減らすには、次の2つのうちどちらかの方針をとる。

a. 二分探索  
    「カードiが必要 かつ a_i <= a_j => カードjも必要」といえる。つまり、単調性がある。よって、N枚すべてを調べるのではなく二分探索をすることにより O(K N log N) が実現できる。
b. 双方向からの途中経過を利用  
    ナップサック問題の dp を 1→N、N→1の双方向から行って、途中経過を記録しておく。カードiを使わない場合の計算は、1〜i-1 と i+1〜N の2つの結果を元に O(K) で計算することができる。よって全体で O(K N) が実現できる。


### 計算量

O( K N log N ) もしくは O( K N )


### keywords

ナップサック問題, 二分探索, dp, 双方向

