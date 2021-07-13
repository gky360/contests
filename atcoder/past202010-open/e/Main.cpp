/*
[past202010-open] E - アナグラム
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

int N;
string S;

string solve() {
    string T = S;
    do {
        next_permutation(ALL(T));
        string rt = T;
        reverse(ALL(rt));
        if (T != S && rt != S) return T;
    } while (T != S);

    return "None";
}

int main() {
    cin >> N;
    cin >> S;

    cout << solve() << endl;

    return 0;
}
