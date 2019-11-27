/*
[agc034] A - Kenken Race
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

int N, A, B, C, D;
string s;

bool solve() {
    for (int i = 0; i < N - 1; i++) {
        if (s[i] == '#' && s[i + 1] == '#' &&
            ((A < i && i < C) || (B < i && i < D))) {
            return false;
        }
    }

    if (C < D) {
        return true;
    }

    bool can_pass = false;
    int cnt = 0;
    for (int i = B - 1; i <= D + 1; i++) {
        if (s[i] == '.') {
            cnt++;
            if (cnt >= 3) {
                can_pass = true;
                break;
            }
        } else {
            cnt = 0;
        }
    }

    return can_pass;
}

int main() {
    cin >> N >> A >> B >> C >> D;
    A--;
    B--;
    C--;
    D--;
    cin >> s;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
