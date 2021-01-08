/*
[abc167] F - Bracket Sequencing
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

const int MAX_N = 1e6;
const int INF = 1e9;

int N;
string S[MAX_N];
int A[MAX_N], B[MAX_N];

ll solve() {
    REP(i, N) {
        int a = 0, b = 0;
        REP(j, S[i].length()) {
            char c = S[i][j];
            (c == ')') ? a++ : b++;
            A[i] = max(A[i], a - b);
        }
    }
    REP(i, N) {
        int a = 0, b = 0;
        for (int j = S[i].length() - 1; j >= 0; j--) {
            char c = S[i][j];
            (c == ')') ? a++ : b++;
            B[i] = max(B[i], b - a);
        }
    }

    vector<pii> x;
    REP(i, N) x.push_back(pii(B[i] - A[i] >= 0 ? A[i] : INF - B[i], i));
    sort(ALL(x));

    int h = 0;
    for (auto &xi : x) {
        int i = xi.second;
        if (h - A[i] < 0) return false;
        h += B[i] - A[i];
    }
    if (h != 0) return false;

    return true;
}

int main() {
    cin >> N;
    REP(i, N) cin >> S[i];

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
