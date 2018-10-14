/*
[abc110] B - 1 Dimensional World's Tale
*/

#include <algorithm>
#include <cmath>
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

const int MAX_N = 100;
const int MAX_M = 100;
const int INF = 1e8;

int N, M, X, Y;
int max_x = -INF, min_y = INF;

int solve() { return (max_x < min_y) && (max_x < Y) && (X < min_y); }

int main() {
    cin >> N >> M >> X >> Y;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        max_x = max(max_x, x);
    }
    for (int i = 0; i < M; i++) {
        int y;
        cin >> y;
        min_y = min(min_y, y);
    }

    cout << (solve() ? "No War" : "War") << endl;

    return 0;
}
