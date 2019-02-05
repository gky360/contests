/*
[abc106] C - To Infinity
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
int K;

char solve() {
    int pos = S.find_first_not_of('1');
    if (pos == string::npos || K <= pos) {
        return '1';
    }
    return S[pos];
}

int main() {
    cin >> S;
    cin >> K;

    cout << solve() << endl;

    return 0;
}
