/*
[abc159] E - Dividing Chocolate
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double DD;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(c) (c).begin(), (c).end()

const int MAX_H = 10;
const int MAX_W = 1000;
const int INF = MAX_H + MAX_W;

int H, W, K;
string S[MAX_H];

int calc(vector<vector<int>>& grps) {
    int h = grps.size();
    vector<int> s(h);
    int pre_w = 0, ret = 0;
    REP(j, W) {
        bool ng = false;
        REP(i, h) {
            if (s[i] + grps[i][j] > K) {
                ng = true;
                break;
            }
            s[i] += grps[i][j];
        }
        if (ng) {
            if (j == pre_w) return INF;
            pre_w = j;
            s = vector<int>(h);
            REP(i, h) s[i] = grps[i][j];
            ret++;
        }
    }
    return ret;
}

int solve() {
    int ans = INF;
    for (int p = 1 << (H - 1); p < (1 << H); p++) {
        vector<vector<int>> grps;
        vector<int> grp(W);
        int cnt = 0;
        REP(i, H) {
            REP(j, W) { grp[j] += S[i][j] - '0'; }
            if ((p >> i) & 1) {
                grps.push_back(grp);
                grp = vector<int>(W);
                cnt++;
            }
        }
        ans = min(ans, calc(grps) + cnt - 1);
    }

    return ans;
}

int main() {
    cin >> H >> W >> K;
    REP(i, H) cin >> S[i];

    cout << solve() << endl;

    return 0;
}
