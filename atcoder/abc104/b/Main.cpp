/*
[abc104] B - AcCepted
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

string S;

bool solve() {
    if (S[0] != 'A') {
        return false;
    }

    int pos = -1;
    for (int i = 2; i <= (int)S.length() - 2; i++) {
        if (S[i] == 'C') {
            if (pos != -1) {
                return false;
            }
            pos = i;
        }
    }
    if (pos == -1) {
        return false;
    }

    for (int i = 1; i < (int)S.length(); i++) {
        if (i == pos) {
            continue;
        }
        if (S[i] < 'a' || 'z' < S[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    cin >> S;

    cout << (solve() ? "AC" : "WA") << endl;

    return 0;
}
