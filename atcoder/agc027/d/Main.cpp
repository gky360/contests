/*
[agc027] D - Modulo Matrix
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

const int MAX_N = 500;
const int MAX_PRIME = 10000;

ll gcd(ll a, ll b) {
    while (b > 0) {
        swap(a %= b, b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    ll d = gcd(a, b);
    return (a / d) * (b / d) * d;
}

int N;
vector<int> primes;

void eratos() {
    vector<bool> is_prime(MAX_PRIME, true);
    for (int i = 2; i < MAX_PRIME; i++) {
        if (!is_prime[i]) {
            continue;
        }
        primes.push_back(i);
        for (int j = 2 * i; j < MAX_PRIME; j += i) {
            is_prime[j] = false;
        }
    }
}

void solve(vector<vector<ll>>& ans) {
    eratos();

    ans.resize(MAX_N);
    for (int i = 0; i < MAX_N; i++) {
        ans[i].resize(MAX_N);
    }

    for (int i = 0; i < MAX_N; i++) {
        for (int j = (i % 2); j < MAX_N; j += 2) {
            int p = (i + j) / 2;
            int q = (i - j + MAX_N) / 2;
            ans[i][j] =
                primes[((p % 2 == 0) ? (p / 2) : (MAX_N - 1 - p / 2))] *
                primes[((q % 2 == 0) ? (q / 2) : (MAX_N - 1 - q / 2)) + MAX_N];
        }
    }

    int di[4] = {0, 1, 0, -1};
    int dj[4] = {-1, 0, 1, 0};
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 1 - (i % 2); j < MAX_N; j += 2) {
            ans[i][j] = 1;
            for (int k = 0; k < 4; k++) {
                if (0 <= i + di[k] && i + di[k] < MAX_N && 0 <= j + dj[k] &&
                    j + dj[k] < MAX_N) {
                    ans[i][j] = lcm(ans[i][j], ans[i + di[k]][j + dj[k]]);
                }
            }
            ans[i][j]++;
        }
    }
}

int main() {
    cin >> N;

    vector<vector<ll>> ans;
    solve(ans);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
