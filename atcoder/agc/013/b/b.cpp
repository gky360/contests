// AtCoder Grand Contest 013
// B - Hamiltonish Path

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int MAX_N = 100000;

int N, M;
vector<int> G[MAX_N];
deque<int> path;
bool visited[MAX_N];

int main() {

    int v;
    int a, b;
    bool proceed;

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    memset(visited, 0, sizeof(visited));
    path.push_back(0);
    visited[0] = true;

    for (int d = 1; d >= -1; d -= 2) {
        proceed = true;
        while (proceed) {
            proceed = false;
            v = (d > 0) ? path.back() : path.front();
            for (int to : G[v]) {
                if (!visited[to]) {
                    visited[to] = true;
                    proceed = true;
                    if (d > 0) {
                        path.push_back(to);
                    } else {
                        path.push_front(to);
                    }
                    break;
                }
            }
        }
    }

    cout << path.size() << endl;
    for (int i = 0; i < (int)path.size(); i++) {
        cout << path[i] + 1 << (i == (int)path.size() - 1 ? '\n' : ' ');
    }

    return 0;

}



