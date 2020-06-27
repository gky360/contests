/*
[abc145] B - Echo
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int N;
string S;

bool solve() {
    if (N % 2 == 1) {
        return false;
    }
    int L = N / 2;
    for (int i = 0; i < L; i++) {
        if (S[i] != S[i + L]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> N;
    cin >> S;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
