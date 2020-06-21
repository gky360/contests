/*
[nikkei2019-2-qual] A - Sum of Two Integers
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int N;

ll solve() { return (N - 1) / 2; }

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
