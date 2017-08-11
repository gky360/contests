// AtCoder Regular Contest 079
// C - Cat Snuke and a Voyage

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int MAX_N = 200000;

int N, M;
bool trans[MAX_N];

int main() {

    int a, b;
    bool ans = false;

    cin >> N >> M;
    memset(trans, 0, sizeof(trans));
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        a--; b--;
        if (b == 0 || b == N - 1) {
            swap(a, b);
        }
        if (a == 0 || a == N - 1) {
            if (trans[b]) {
                ans = true;
                break;
            }
            trans[b] = true;
        }
    }

    cout << (ans ? "POSSIBLE" : "IMPOSSIBLE") << endl;

    return 0;

}



