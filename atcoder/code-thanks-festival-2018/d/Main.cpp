/*
[code-thanks-festival-2018] D - Concatenation
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

string s;

int solve() {
    char top = s[0];
    int ans = 1;
    for (int i = 1; i < (int)s.length(); i++) {
        if (s[i] <= top) {
            ans++;
            top = s[i];
        }
    }

    return ans;
}

int main() {
    cin >> s;

    cout << solve() << endl;

    return 0;
}
