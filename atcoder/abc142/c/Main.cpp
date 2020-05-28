/*
[abc142] C - Go to School
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
int A[MAX_N];

void solve() {
    vector<pii> ais;
    for (int i = 0; i < N; i++) {
        ais.push_back({A[i], i});
    }
    sort(ALL(ais));

    for (auto& ai : ais) {
        cout << ai.second + 1 << " ";
    }
    cout << endl;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    solve();

    return 0;
}
