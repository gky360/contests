/*
[abc165] C - Many Requirements
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 10;
const int MAX_M = 10;
const int MAX_Q = 50;

int N, M, Q;
int a[MAX_Q], b[MAX_Q], c[MAX_Q], d[MAX_Q];
int dp[MAX_N + 1][MAX_M + 1];

int calc(vector<int> &nums) {
    int ret = 0;
    for (int i = 0; i < Q; i++) {
        if (nums[b[i]] - nums[a[i]] == c[i]) {
            ret += d[i];
        }
    }

    return ret;
}

int dfs(vector<int> &nums) {
    if ((int)nums.size() == N) {
        return calc(nums);
    }

    int ans = 0;
    int l = nums.empty() ? 1 : nums.back();
    for (int i = l; i <= M; i++) {
        nums.push_back(i);
        ans = max(ans, dfs(nums));
        nums.pop_back();
    }

    return ans;
}

ll solve() {
    vector<int> nums;
    return dfs(nums);
}

int main() {
    cin >> N >> M >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--, b[i]--;
    }

    cout << solve() << endl;

    return 0;
}
