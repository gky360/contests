/*
[yahoo-procon2019-qual] B - Path
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

int a[3], b[3];
int cnt[4];

bool solve() {
    for (int i = 0; i < 3; i++) {
        cnt[a[i]]++;
        cnt[b[i]]++;
    }
    for (int i = 0; i < 4; i++) {
        if (cnt[i] >= 3) {
            return false;
        }
    }

    return true;
}

int main() {
    for (int i = 0; i < 3; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }

    cout << (solve() ? "YES" : "NO") << endl;

    return 0;
}
