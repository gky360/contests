/*
[arc103] E - Tr/ee
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

int N;
string s;

bool solve(vector<pii>& ans) {
    if (s[0] == '0' || s[N - 1] == '1') {
        return false;
    }
    ans.resize(N - 1);
    s[N - 1] = '1';

    int par = 0;
    for (int i = 0; i < N - 1; i++) {
        if (s[i] != s[N - i - 2]) {
            return false;
        }
        while (!(i < par && s[par] == '1')) {
            par++;
        }
        ans[i] = pii(i, par);
    }

    return true;
}

int main() {
    cin >> s;
    N = s.length();

    vector<pii> ans;
    if (!solve(ans)) {
        cout << -1 << endl;
        return 0;
    }
    for (auto& p : ans) {
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }

    return 0;
}
