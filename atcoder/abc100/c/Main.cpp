/*
[abc100] C - *3 or /2
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

const int MAX_N = 10000;

int N;
int a[MAX_N];

ll solve() {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int b = a[i]; b > 0 && b % 2 == 0; b /= 2) {
            ans++;
        }
    }
    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << solve() << endl;

    return 0;
}
