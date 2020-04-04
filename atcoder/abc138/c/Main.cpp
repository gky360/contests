/*
[abc138] C - Alchemist
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
int v[MAX_N];

double solve() {
    sort(v, v + N);
    double ans = (double)v[0] / (1LL << (N - 1));
    for (int i = 1; i < N; i++) {
        ans += (double)v[i] / (1LL << (N - i));
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    cout << setprecision(16) << solve() << endl;

    return 0;
}
