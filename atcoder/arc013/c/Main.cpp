/*
[arc013] C - 笑いをとれるかな？
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1000;
const int MAX_M = 100;

int N;
int X[3][MAX_N];
int M[MAX_N];
int x[3][MAX_N][MAX_M];

bool solve() {
    vector<int> nim;

    for (int i = 0; i < N; i++) {
        int l[3], r[3];
        for (int d = 0; d < 3; d++) {
            l[d] = x[d][i][0];
            r[d] = x[d][i][0];
        }
        for (int j = 0; j < M[i]; j++) {
            for (int d = 0; d < 3; d++) {
                l[d] = min(l[d], x[d][i][j]);
                r[d] = max(r[d], x[d][i][j]);
            }
        }
        for (int d = 0; d < 3; d++) {
            nim.push_back(l[d]);
            nim.push_back(X[d][i] - 1 - r[d]);
        }
    }

    int ans = 0;
    for (int n : nim) {
        ans ^= n;
    }
    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int d = 0; d < 3; d++) {
            cin >> X[d][i];
        }
        cin >> M[i];
        for (int j = 0; j < M[i]; j++) {
            for (int d = 0; d < 3; d++) {
                cin >> x[d][i][j];
            }
        }
    }

    cout << (solve() ? "WIN" : "LOSE") << endl;

    return 0;
}
