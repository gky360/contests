// ARC093
// D - Grid Components

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int H = 100, W = 100;
char wb[2] = {'.', '#'};

int AB[2];
char ans[H][W];

void solve() {
    int cnt[2] = {0, 0};
    for (int i = 0; i < H; i++) {
        int p = i / (H / 2);
        for (int j = 0; j < W; j++) {
            int q = ((i - p * (H / 2)) % 2) * (j % 2);
            cnt[p] += q;
            int r = (cnt[p] <= AB[p] - 1) ? 1 : 0;
            ans[i][j] = wb[(p + q * r + 1) % 2];
        }
    }
}

int main() {
    cin >> AB[0] >> AB[1];

    solve();

    cout << H << " " << W << endl;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}
