/*
[abc143] D - Triangles
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 2000;

int N;
int L[MAX_N];

ll solve() {
    sort(L, L + N);

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        int b = L[i];
        for (int j = i + 1; j < N; j++) {
            int c = L[j];
            ans += max(0L, i - (upper_bound(L, L + i, c - b) - L));
        }
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }

    cout << solve() << endl;

    return 0;
}
