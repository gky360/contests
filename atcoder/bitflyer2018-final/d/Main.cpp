/*
[bitflyer2018-final] D - 数列 XOR
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

const int MAX_B = 60;

vector<ll> regularize(vector<ll> a) {
    int N = a.size();
    int c = 0;
    for (int i = 0; i <= MAX_B; i++) {
        int p = -1;
        for (int j = c; j < N; j++) {
            if (a[j] & (1LL << i)) {
                p = j;
                break;
            }
        }
        if (p == -1) {
            continue;
        }
        swap(a[c], a[p]);
        for (int j = 0; j < N; j++) {
            if (j == c) {
                continue;
            }
            if (a[j] & (1LL << i)) {
                a[j] ^= a[c];
            }
        }
        c++;
    }
    return a;
}

ll solve(const int N, const vector<ll>& a, const vector<ll>& b) {
    return regularize(a) == regularize(b);
}

int main() {
    int N;
    cin >> N;
    vector<ll> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    cout << (solve(N, a, b) ? "Yes" : "No") << endl;

    return 0;
}
