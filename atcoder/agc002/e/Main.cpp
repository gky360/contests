/*
[agc002] E - Candy Piles
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;

int N;
int a[MAX_N];

ll solve() {
    sort(a, a + N, greater<int>());

    int l = 0;
    while (l + 1 < N && a[l + 1] > l + 1) {
        l++;
    }
    int r = l;
    while (r + 1 < N && a[r + 1] > l) {
        r++;
    }

    return (a[l] - l - 1) % 2 == 1 || (r - l) % 2 == 1;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << (solve() ? "First" : "Second") << endl;

    return 0;
}
