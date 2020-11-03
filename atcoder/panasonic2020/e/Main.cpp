/*
[panasonic2020] E - Three Substrings
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(c) (c).begin(), (c).end()

const int N = 2000;
const int D = 2 * N;

string a, b, c;
int A, B, C;
bool ab[2 * D + 1], bc[2 * D + 1], ca[2 * D + 1];

bool match(char c1, char c2) { return c1 == '?' || c2 == '?' || c1 == c2; }

ll solve() {
    REP(i, A) REP(j, B) if (!match(a[i], b[j])) ab[i - j + D] = true;
    REP(i, B) REP(j, C) if (!match(b[i], c[j])) bc[i - j + D] = true;
    REP(i, C) REP(j, A) if (!match(c[i], a[j])) ca[i - j + D] = true;

    int ans = A + B + C;
    for (int i = -2 * N; i <= 2 * N; i++) {
        for (int j = -2 * N; j <= 2 * N; j++) {
            if (!ab[i + D] && !bc[j - i + D] && !ca[-j + D]) {
                int l = min(0, min(i, j));
                int r = max(A, max(i + B, j + C));
                ans = min(ans, r - l);
            }
        }
    }

    return ans;
}

int main() {
    cin >> a >> b >> c;
    A = a.length(), B = b.length(), C = c.length();

    cout << solve() << endl;

    return 0;
}
