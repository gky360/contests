/*
[agc032] A - Limited Insertion
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 100;

int N;
vector<int> b;

void solve() {
    deque<int> ans;

    for (int j = 0; j < N; j++) {
        bool updated = false;
        for (int i = b.size() - 1; i >= 0; i--) {
            if (b[i] == i) {
                b.erase(b.begin() + i);
                ans.push_front(i);
                updated = true;
                break;
            }
        }

        if (!updated) {
            cout << -1 << endl;
            return;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] + 1 << endl;
    }
}

int main() {
    cin >> N;
    b.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> b[i];
        b[i]--;
    }

    solve();

    return 0;
}
