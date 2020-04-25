// topological sort

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_V = 100000;

vector<int> g[MAX_V];

bool visit(int v, vector<int> &order, vector<int> &color) {
    color[v] = 1;
    for (int to : g[v]) {
        if (color[to] == 2) continue;
        if (color[to] == 1 || !visit(to, order, color)) return false;
    }
    order.push_back(v);
    color[v] = 2;
    return true;
}

bool topological_sort(int n, vector<int> &order) {
    vector<int> color(n);
    for (int v = 0; v < n; v++) {
        if (!color[v] && !visit(v, order, color)) return false;
    }
    reverse(ALL(order));
    return true;
}

int main() { return 0; }
