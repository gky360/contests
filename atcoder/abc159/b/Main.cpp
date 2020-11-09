/*
[abc159] B - String Palindrome
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

string S;

ll solve() {
    int N = S.length();
    REP(i, (N - 1) / 2) {
        if (S[i] != S[N - i - 1]) return false;
    }
    REP(i, N / 2) {
        if (S[i] != S[N / 2 - i - 1] ||
            S[i + N / 2 + 1] != S[N / 2 - i - 1 + N / 2 + 1])
            return false;
    }
    return true;
}

int main() {
    cin >> S;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
