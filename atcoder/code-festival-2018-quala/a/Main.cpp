/*
[code-festival-2018-quala] A - 配点
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

int A, B, C;
int S;

bool solve() {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                if (A + B + C + i + j + k == S) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> A >> B >> C;
    cin >> S;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
