/*
[abc150] C - Count Order
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 8;

int N;
vector<int> P, Q;

int ord(vector<int> t) {
    vector<int> a(N);
    for (int i = 1; i <= N; i++) {
        a[i - 1] = i;
    }
    int ret = 0;
    while (a != t) {
        next_permutation(ALL(a));
        ret++;
    }
    return ret;
}

ll solve() { return abs(ord(P) - ord(Q)); }

int main() {
    cin >> N;
    P.resize(N);
    Q.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> Q[i];
    }

    cout << solve() << endl;

    return 0;
}
