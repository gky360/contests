// AtCoder Regular Contest 076
// E - Connected?

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;


const int MAX_N = 100000;

ll R, C;
int N;
vector<pair<ll, int>> border;
stack<int> s;
bool used[MAX_N];

int main() {

    ll x[2], y[2], idx;
    bool is_border;


    cin >> R >> C >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[0] >> y[0] >> x[1] >> y[1];
        is_border = true;
        for (int j = 0; j < 2; j++) {
            is_border = is_border && (x[j] % R == 0 || y[j] % C == 0);
        }
        if (!is_border) {
            continue;
        }
        for (int j = 0; j < 2; j++) {
            if (x[j] == 0) {
                idx = C - y[j];
            } else if (y[j] == 0) {
                idx = C + x[j];
            } else if (x[j] == R) {
                idx = C + R + y[j];
            } else if (y[j] == C) {
                idx = C + R + C + R - x[j];
            }
            border.push_back(make_pair(idx, i));
        }
    }

    memset(used, 0, sizeof(used));
    sort(border.begin(), border.end());

    for (auto &p : border) {
        if (used[p.second]) {
            if (s.top() != p.second) {
                cout << "NO" << endl;
                return 0;
            }
            s.pop();
        } else {
            s.push(p.second);
            used[p.second] = true;
        }
    }

    cout << "YES" << endl;

    return 0;

}



