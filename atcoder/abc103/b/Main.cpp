/*
[abc103] B - String Rotation
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

string S, T;
int N;

ll solve() {
    for (int i = 0; i < N; i++) {
        bool can = true;
        for (int j = 0; j < N; j++) {
            can = can && (S[j] == T[(i + j) % N]);
        }
        if (can) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> S;
    cin >> T;
    N = S.length();

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
