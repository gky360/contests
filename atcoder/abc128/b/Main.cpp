/*
[abc128] B - Guidebook
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

const int MAX_N = 100;

int N;
string S[MAX_N];
int P[MAX_N];
vector<pair<pair<string, int>, int>> ls;

void solve() {
    for (int i = 0; i < N; i++) {
        ls.push_back({{S[i], -P[i]}, i + 1});
    }
    sort(ls.begin(), ls.end());
    for (int i = 0; i < N; i++) {
        cout << ls[i].second << endl;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> P[i];
    }

    solve();

    return 0;
}
