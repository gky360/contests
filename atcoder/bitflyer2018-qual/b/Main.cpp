/*
[bitflyer2018-qual] B - 洋菓子店
*/

#include <algorithm>
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

int A, B, N;
string X;

pii solve() {
    int a = A, b = B;
    for (int i = 0; i < N; i++) {
        if (X[i] == 'S' || (X[i] == 'E' && a >= b)) {
            a = max(a - 1, 0);
        } else {
            b = max(b - 1, 0);
        }
    }
    return pii(a, b);
}

int main() {
    cin >> A >> B >> N;
    cin >> X;

    pii res = solve();
    cout << res.first << endl;
    cout << res.second << endl;

    return 0;
}
