/*
[abc161] E - Yutori
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double DD;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(c) (c).begin(), (c).end()

int N, K, C;
string S;

vector<int> calc() {
    vector<int> ret;
    int prev = -C - 1;
    REP(i, N) {
        if (S[i] == 'o' && i > prev + C && (int)ret.size() < K) {
            ret.push_back(i);
            prev = i;
        }
    }
    return ret;
}

void solve() {
    vector<int> s1, s2;
    s1 = calc();
    reverse(ALL(S));
    s2 = calc();
    for (int i = 0; i < K; i++) {
        if (s1[i] == N - 1 - s2[K - 1 - i]) cout << s1[i] + 1 << endl;
    }
}

int main() {
    cin >> N >> K >> C;
    cin >> S;

    solve();

    return 0;
}
