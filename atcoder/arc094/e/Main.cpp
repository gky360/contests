// ARC094
// E - Tozan and Gezan

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int INF = 1e9 + 1;

int main() {
    int N, c;
    ll s;

    cin >> N;

    s = 0;
    c = INF;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        s += a;
        if (a > b && c > b) {
            c = b;
        }
    }

    if (c == INF) {
        cout << 0 << endl;
        return 0;
    }
    cout << s - c << endl;

    return 0;
}
