/*
[abc170] E - Smart Infants
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

const int MAX_N = 2e5;
const int MAX_Q = 2e5;
const int MAX_K = 2e5;

int N, Q;
ll A[MAX_N];
int B[MAX_N];
int C[MAX_Q], D[MAX_Q];
multiset<ll> ks[MAX_K];
multiset<ll> m;

void solve() {
    REP(i, N) ks[B[i]].insert(A[i]);
    REP(k, MAX_K) {
        if (ks[k].size() > 0) m.insert(*ks[k].rbegin());
    }

    REP(i, Q) {
        m.erase(m.find(*ks[B[C[i]]].rbegin()));
        ks[B[C[i]]].erase(ks[B[C[i]]].find(A[C[i]]));
        if (ks[B[C[i]]].size() > 0) m.insert(*ks[B[C[i]]].rbegin());
        B[C[i]] = D[i];
        if (ks[B[C[i]]].size() > 0) m.erase(m.find(*ks[B[C[i]]].rbegin()));
        ks[B[C[i]]].insert(A[C[i]]);
        m.insert(*ks[B[C[i]]].rbegin());

        cout << *m.begin() << endl;
    }
}

int main() {
    cin >> N >> Q;
    REP(i, N) {
        cin >> A[i] >> B[i];
        B[i]--;
    }
    REP(i, Q) {
        cin >> C[i] >> D[i];
        C[i]--, D[i]--;
    }

    solve();

    return 0;
}
