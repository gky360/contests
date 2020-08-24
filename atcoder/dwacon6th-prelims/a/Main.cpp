/*
[dwacon6th-prelims] A - Falling Asleep
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 50;

int N;
string s[MAX_N];
int t[MAX_N];
string X;

ll solve() {
    bool asleep = false;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (asleep) {
            ans += t[i];
        }
        asleep = asleep || s[i] == X;
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s[i] >> t[i];
    }
    cin >> X;

    cout << solve() << endl;

    return 0;
}
