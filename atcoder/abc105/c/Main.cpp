/*
[abc105] C - Base -2 Number
*/

#include <algorithm>
#include <bitset>
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

const int MAX_K = 32;

int N;

string solve() {
    bitset<MAX_K> ans;
    int n = N;

    int k;
    for (k = 0; n != 0; k++) {
        if (n & 1) {
            n--;
            ans.set(k);
        }
        n /= -2;
    }
    int len = max(1, k);

    string ans_str = ans.to_string().substr(MAX_K - len, len);

    return ans_str;
}

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
