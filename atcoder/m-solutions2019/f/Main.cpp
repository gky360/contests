/*
[m-solutions2019] F - Random Tournament
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 2000;

int N;
bitset<MAX_N> A[MAX_N];

bitset<MAX_N> dpl[MAX_N], dpr[MAX_N];

ll solve() {
    for (int i = 0; i < N; i++) {
        dpl[i][i] = dpr[i][i] = true;
    }
    for (int l = 1; l < N; l++) {
        for (int i = 0; i + l < N; i++) {
            int j = i + l;
            dpl[j][i] = (A[i] & dpl[j] & dpr[i + 1]).any();
        }
        for (int j = l; j < N; j++) {
            int i = j - l;
            dpr[i][j] = (A[j] & dpr[i] & dpl[j - 1]).any();
        }
    }

    int ans = (dpr[0] & dpl[N - 1]).count();
    return ans;
}

int main() {
    cin >> N;
    for (int i = 1; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < i; j++) {
            A[i][j] = s[j] == '1';
            A[j][i] = !A[i][j];
        }
    }

    cout << solve() << endl;

    return 0;
}
