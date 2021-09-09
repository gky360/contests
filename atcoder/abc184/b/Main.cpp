/*
[abc184] B - Quizzes
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

int N, X;
string S;

ll solve() {
    int ans = X;
    for (char c : S) {
        ans = (c == 'o' ? ans + 1 : max(0, ans - 1));
    }
    return ans;
}

int main() {
    cin >> N >> X;
    cin >> S;

    cout << solve() << endl;

    return 0;
}
