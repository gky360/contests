/*
[JAG2014Spring] J - Unfair Game
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;

int N;
ll A, B;
ll S[MAX_N];

ll grundy(ll n, ll m) { return n % (m + 1); }

bool solve() {
    ll g = 0;
    for (int i = 0; i < N; i++) {
        g ^= grundy(S[i], B);
    }

    if (A == B) {
        return g;
    }
    if (A > B) {
        if (g) {
            return true;
        }
        for (int i = 0; i < N; i++) {
            if (S[i] >= B + 1) {
                return true;
            }
        }
        return false;
    }

    int cnt = 0;
    int si = -1;
    g = 0;
    for (int i = 0; i < N; i++) {
        g ^= grundy(S[i], A);
        if (S[i] >= A + 1) {
            cnt++;
            si = i;
        }
    }
    if (cnt >= 2 || !g) {
        return false;
    }
    if (cnt == 0) {
        return true;
    }

    g ^= grundy(S[si], A);
    ll t = S[si] - S[si] % (A + 1);
    ll s1 = t + g, s2 = t - (A + 1) + g;
    return (0 <= s1 && s1 <= A && 1 <= S[si] - s1 && S[si] - s1 <= A) ||
           (0 <= s2 && s2 <= A && 1 <= S[si] - s2 && S[si] - s2 <= A);
}

int main() {
    cin >> N >> A >> B;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    cout << (solve() ? "Hanako" : "Jiro") << endl;

    return 0;
}
