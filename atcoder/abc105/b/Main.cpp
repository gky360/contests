/*
[abc105] B - Cakes and Donuts
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

bool solve() {
    for (int i = 0; i <= N; i += 4) {
        if ((N - i) % 7 == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> N;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
