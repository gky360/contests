/*
[code-festival-2018-qualb] A - Probability of Participation
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

ll solve() { return 100 - 100 / N; }

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
