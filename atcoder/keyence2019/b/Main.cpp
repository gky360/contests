/*
[keyence2019] B - KEYENCE String
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

string S;

bool solve() {
    int N = S.length();
    for (int l = 0; l <= N; l++) {
        for (int r = l; r <= N; r++) {
            if (S.substr(0, l) + S.substr(r, N - r) == "keyence") {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> S;

    cout << (solve() ? "YES" : "NO") << endl;

    return 0;
}
