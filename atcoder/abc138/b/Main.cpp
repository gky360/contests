/*
[abc138] B - Resistors in Parallel
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 100;

int N;
int A[MAX_N];

double solve() {
    double b = 0;
    for (int i = 0; i < N; i++) {
        b += 1.0 / A[i];
    }

    double ans = 1.0 / b;

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << setprecision(16) << solve() << endl;

    return 0;
}
