/*
[nikkei2019-qual] B - Touitsu
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

int N;
string A, B, C;

ll solve() {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        if (A[i] != B[i]) cnt++;
        if (B[i] != C[i]) cnt++;
        if (C[i] != A[i]) cnt++;
        ans += max(0, cnt - 1);
    }

    return ans;
}

int main() {
    cin >> N;
    cin >> A;
    cin >> B;
    cin >> C;

    cout << solve() << endl;

    return 0;
}
