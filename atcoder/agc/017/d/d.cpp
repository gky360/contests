// AtCoder Grand Contest 017
// D - Game on Tree

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;


const int MAX_N = 100000;

int N;
vector<int> G[MAX_N];
bool visited[MAX_N];

int calc_grundy(int v) {
    int grundy = 0;

    visited[v] = true;
    for (int to : G[v]) {
        if (visited[to]) {
            continue;
        }
        grundy ^= (calc_grundy(to) + 1);
    }

    return grundy;
}

int main() {

    int x, y;

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> x >> y; x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    fill(visited, visited + N, false);

    cout << (calc_grundy(0) != 0 ? "Alice" : "Bob") << endl;

    return 0;

}



