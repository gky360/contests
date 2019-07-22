/*
[nikkei2019-qual] C - Different Strokes
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

const int MAX_N = 1e5;

int N;
pii AB[MAX_N];

ll solve() {
    sort(AB, AB + N,
         [](pii a, pii b) { return a.first + a.second > b.first + b.second; });

    ll ans = 0;
    for (int i = 0; i < N; i += 2) {
        ans += AB[i].first;
    }
    for (int i = 1; i < N; i += 2) {
        ans -= AB[i].second;
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> AB[i].first >> AB[i].second;
    }

    cout << solve() << endl;

    return 0;
}
