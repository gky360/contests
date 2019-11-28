/*
[agc034] B - ABC
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

string s;
int N;

ll solve() {
    ll ans = 0;
    int cnt_a = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] == 'A') {
            cnt_a++;
        } else if (i < N - 1 && s[i] == 'B' && s[i + 1] == 'C') {
            ans += cnt_a;
        } else if (i > 0 && s[i - 1] == 'B' && s[i] == 'C') {
        } else {
            cnt_a = 0;
        }
    }

    return ans;
}

int main() {
    cin >> s;
    N = s.length();

    cout << solve() << endl;

    return 0;
}
