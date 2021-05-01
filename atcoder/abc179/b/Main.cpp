/*
[abc179] B - Go to Jail
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

const int MAX_N = 100;

int N;
int D[MAX_N][2];

ll solve() {
    int cnt = 0;
    REP(i, N) {
        if (D[i][0] == D[i][1]) {
            cnt++;
            if (cnt == 3) {
                return true;
            }
        } else {
            cnt = 0;
        }
    }

    return false;
}

int main() {
    cin >> N;
    REP(i, N) cin >> D[i][0] >> D[i][1];

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
