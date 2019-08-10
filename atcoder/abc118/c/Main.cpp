/*
[abc118] C - Monsters Battle Royale
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int gcd(int a, int b) {
    while (b > 0) {
        swap(a %= b, b);
    }
    return a;
}

const int MAX_N = 1e5;

int N;
int A[MAX_N];

ll solve() {
    int ans = A[0];
    for (int i = 1; i < N; i++) {
        ans = gcd(ans, A[i]);
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
