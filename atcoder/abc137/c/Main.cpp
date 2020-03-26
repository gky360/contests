/*
[abc137] C - Green Bin
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;

int N;
string s[MAX_N];
int cnt[MAX_N]['z' - 'a' + 1];
vector<int> idx;

bool same(int i, int j) {
    for (int c = 0; c < 'z' - 'a' + 1; c++) {
        if (cnt[idx[i]][c] != cnt[idx[j]][c]) {
            return false;
        }
    }
    return true;
}

ll solve() {
    for (int i = 0; i < N; i++) {
        for (char c : s[i]) {
            cnt[i][c - 'a']++;
        }
    }

    for (int i = 0; i < N; i++) {
        idx.push_back(i);
    }
    sort(idx.begin(), idx.end(), [](int i, int j) {
        for (int c = 0; c < 'z' - 'a'; c++) {
            if (cnt[i][c] != cnt[j][c]) {
                return cnt[i][c] < cnt[j][c];
            }
        }
        return cnt[i]['z' - 'a'] < cnt[j]['z' - 'a'];
    });

    ll ans = 0;
    for (int i = 1, pre = 0; i < N; i++) {
        if (same(i, pre)) {
            ans += i - pre;
        } else {
            pre = i;
        }
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }

    cout << solve() << endl;

    return 0;
}
