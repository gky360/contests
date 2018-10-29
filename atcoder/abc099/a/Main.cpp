/*
[abc099] A - ABD
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

int N;

string solve() { return (N < 1000) ? "ABC" : "ABD"; }

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
