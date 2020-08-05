/*
[nikkei2019-2-final] A - Count Triplets
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 5000;

int N;
int A[MAX_N];
int cl[MAX_N], cr[MAX_N];

ll solve() {
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        int cl = 0, cr = 0;
        for (int j = 0; j < N; j++) {
            if (j < i && A[j] < A[i]) cl++;
            if (i < j && A[j] < A[i]) cr++;
        }
        ans += cl * cr;
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
