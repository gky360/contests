// ARC089
// C - March

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const string MONTH = "MARCH";
const int M = MONTH.length();
const int K = 3;

int N;
vector<int> cnt(M);

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            if (s[0] == MONTH[j]) {
                cnt[j]++;
                break;
            }
        }
    }

    ll ans = 0;
    int comb = (1 << K) - 1;
    while (comb < (1 << M)) {
        ll prd = 1;
        for (int j = 0; j < M; j++) {
            if (comb & (1 << j)) {
                prd *= cnt[j];
            }
        }
        ans += prd;

        int x = comb & -comb, y = comb + x;
        comb = (((comb & ~y) / x) >> 1) | y;
    }

    cout << ans << endl;

    return 0;
}
