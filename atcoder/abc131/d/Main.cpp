/*
[abc131] D - Megalomania
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 2e5;

int N;
pii BA[MAX_N];

bool solve() {
    sort(BA, BA + N);

    ll s = 0;
    for (int i = 0; i < N; i++) {
        int a = BA[i].second;
        int b = BA[i].first;

        s += a;
        if (s > b) {
            return false;
        }
    }

    return true;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> BA[i].second >> BA[i].first;
    }

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
