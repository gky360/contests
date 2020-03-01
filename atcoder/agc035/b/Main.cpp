/*
[agc035] B - Even Degrees
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;
const int MAX_M = 1e5;

int N, M;
int A[MAX_M], B[MAX_M];
vector<int> g[MAX_N];
bool visited[MAX_N];

void dfs(int v, int par = -1) {
    if (visited[v]) {
        return;
    }
    visited[v] = true;

    int par_e = -1;
    int cnt = 0;
    for (int e : g[v]) {
        int to = A[e] != v ? A[e] : B[e];
        if (to == par) {
            par_e = e;
            continue;
        }
        dfs(to, v);
    }
    for (int e : g[v]) {
        if (v == A[e]) {
            cnt++;
        }
    }
    if (par_e != -1 && cnt % 2 != 0) {
        swap(A[par_e], B[par_e]);
    }
}

void solve() {
    if (M % 2 != 0) {
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i < M; i++) {
        g[A[i]].push_back(i);
        g[B[i]].push_back(i);
    }

    dfs(0);

    for (int i = 0; i < M; i++) {
        cout << A[i] + 1 << " " << B[i] + 1 << endl;
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--, B[i]--;
    }

    solve();

    return 0;
}
