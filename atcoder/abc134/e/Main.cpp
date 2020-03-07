/*
[abc134] E - Sequence Decomposing
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;

int N;
int A[MAX_N];

ll solve() {
    multiset<int> s;

    for (int i = N - 1; i >= 0; i--) {
        auto iter = s.upper_bound(A[i]);
        if (iter != s.end()) {
            s.erase(iter);
        }
        s.insert(A[i]);
    }

    return s.size();
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
