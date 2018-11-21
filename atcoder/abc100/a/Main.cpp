/*
[abc100] A - Happy Birthday!
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

int A, B;

string solve() { return (A <= 8 && B <= 8) ? "Yay!" : ":("; }

int main() {
    cin >> A >> B;

    cout << solve() << endl;

    return 0;
}
