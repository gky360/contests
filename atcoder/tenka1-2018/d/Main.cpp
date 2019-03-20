/*
[tenka1-2018] D - Crossing
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

int calc_num(int a, int b) {
    if (a < b) {
        swap(a, b);
    }
    return a * (a - 1) / 2 + b + 1;
}

bool solve(vector<set<int>>& ans) {
    int k = 0;
    while (k * (k - 1) / 2 < N) {
        k++;
    }
    if (k * (k - 1) / 2 != N) {
        return false;
    }

    ans.resize(k);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (i == j) {
                continue;
            }
            ans[i].insert(calc_num(i, j));
        }
    }

    return true;
}

int main() {
    cin >> N;

    vector<set<int>> ans;
    bool ret = solve(ans);

    if (!ret) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    cout << ans.size() << endl;
    for (set<int>& s : ans) {
        cout << s.size();
        for (int n : s) {
            cout << " " << n;
        }
        cout << endl;
    }

    return 0;
}
