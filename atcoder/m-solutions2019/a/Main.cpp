/*
[m-solutions2019] A - Sum of Interior Angles
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int N;

ll solve() { return 180 * (N - 2); }

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
