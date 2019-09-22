/*
[exawizards2019] C - Snuke the Wizard
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 2e5;
const int MAX_Q = 2e5;

int N, Q;
string s;
char t[MAX_Q], d[MAX_Q];

bool can(int x, int target) {
    for (int i = 0; i < Q; i++) {
        if (t[i] == s[x]) {
            x += d[i] == 'L' ? -1 : 1;
        }
    }

    return x == target;
}

ll solve() {
    ll cnt = 0;
    for (int target : {0, N + 1}) {
        int ok, ng;
        if (target == 0) {
            ok = 0;
            ng = N + 1;
        } else {
            ng = 0;
            ok = N + 1;
        }
        while (abs(ok - ng) > 1) {
            int mid = (ok + ng) / 2;
            if (can(mid, target)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        cerr << "ok: " << ok << endl;
        cnt += abs(ok - target);
    }

    return N - cnt;
}

int main() {
    cin >> N >> Q;
    cin >> s;
    s.insert(s.begin(), '@');
    s.push_back('@');
    for (int i = 0; i < Q; i++) {
        cin >> t[i] >> d[i];
    }

    cout << solve() << endl;

    return 0;
}
