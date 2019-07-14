/*
[ddcc2019-final] B - 大吉数列 (Array of Fortune)
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int N, K;
ll R;

vector<int> solve() {
    ll r = R;
    vector<int> ans, rev;
    for (int i = 0; i < N; i++) {
        if (r >= N - i - K && N - i - K > 0) {
            rev.push_back(i);
            r -= N - i - K;
        } else {
            ans.push_back(i);
        }
    }
    if (r > 0) {
        return {};
    }

    reverse(rev.begin(), rev.end());
    for (int n : rev) {
        ans.push_back(n);
    }

    return ans;
}

int main() {
    cin >> N >> K >> R;

    auto ans = solve();
    if (ans == vector<int>()) {
        cout << "No Luck" << endl;
        return 0;
    }

    for (int num : ans) {
        cout << num + 1 << " ";
    }
    cout << endl;

    return 0;
}
