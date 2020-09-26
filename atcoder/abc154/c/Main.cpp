/*
[abc154] C - Distinct or Not
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 200000;

int N;
int A[MAX_N];

bool solve() {
    map<int, bool> cnt;
    for (int i = 0; i < N; i++) {
        if (cnt[A[i]]) return false;
        cnt[A[i]] = true;
    }
    return true;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << (solve() ? "YES" : "NO") << endl;

    return 0;
}
