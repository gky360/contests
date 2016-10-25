# CODE FESTIVAL 2016 qual C

## [AC-][code-festival-2016-qualc] E - 順列辞書 / Encyclopedia of Permutations

### 方針

[参照](http://code-festival-2016-qualc.contest.atcoder.jp/data/other/code-festival-2016-qualc/editorial.pdf)

#### その他

またも、mod の世界において普通に割り算してしまうというミスではまった。mod の世界では、割り算の代わりに逆元を使おう。

ちなみに、mod の法が $m$ でかつ $m$ が奇数であるときは、 $2^{-1} = (m + 1) / 2 ~({\rm mod}~ m)$ と言う感じで2の逆元が（extgcd とか使わずに）一瞬で求められることに、どなたかのコードを読んだときに気づいた。なるほど。いつか使えそう。


### 計算量

O( N log(N) )


### keywords

bit, 数え上げ, 組み合わせ, mod, 逆元, 階乗

