/*
[soundhound2018-summer-qual] B - Acrostic
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
int W;

string solve() {
    string ret;
    for (int i = 0; i < (int)S.size(); i += W) {
        ret += S[i];
    }
    return ret;
}

int main() {
    cin >> S;
    cin >> W;

    cout << solve() << endl;

    return 0;
}
