/*
[agc024] A - Fairness
*/

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

ll A, B, C, K;

ll solve() { return (K % 2 == 0 ? A - B : B - A); }

int main() {
    cin >> A >> B >> C >> K;

    cout << solve() << endl;

    return 0;
}
