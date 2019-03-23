/*
[abc113] C - ID
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

const int MAX_N = 100000;
const int MAX_M = 100000;

int N, M;
int P[MAX_M], Y[MAX_M];
int cnt[MAX_N];

void solve(vector<string>& ans) {
    vector<pii> ym;
    for (int i = 0; i < M; i++) {
        ym.push_back(pii(Y[i], i));
    }
    sort(ym.begin(), ym.end());

    ans.resize(M);
    for (pii& p : ym) {
        int m = p.second;
        char code[13];
        sprintf(code, "%06d%06d", P[m] + 1, cnt[P[m]] + 1);
        ans[m] = code;
        cnt[P[m]]++;
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> P[i] >> Y[i];
        P[i]--;
    }

    vector<string> ans;
    solve(ans);

    for (string& code : ans) {
        cout << code << endl;
    }

    return 0;
}
