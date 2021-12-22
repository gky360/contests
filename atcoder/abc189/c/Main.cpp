/*
[abc189] C - Mandarin Orange
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

const int MAX_N = 1e4;

int N;
int A[MAX_N];

ll solve() {
    int l[MAX_N], r[MAX_N];
    vector<int> p;
    REP(i, N) {
        while (!p.empty() && A[p.back()] >= A[i]) p.pop_back();
        l[i] = p.empty() ? 0 : (p.back() + 1);
        p.push_back(i);
    }
    p.clear();
    for (int i = N - 1; i >= 0; i--) {
        while (!p.empty() && A[p.back()] >= A[i]) p.pop_back();
        r[i] = p.empty() ? N : p.back();
        p.push_back(i);
    }

    int ans = 0;
    REP(i, N) ans = max(ans, A[i] * (r[i] - l[i]));
    return ans;
}

int main() {
    cin >> N;
    REP(i, N) cin >> A[i];

    cout << solve() << endl;

    return 0;
}
