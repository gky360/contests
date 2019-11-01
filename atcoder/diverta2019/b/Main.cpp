/*
[diverta2019] B - RGB Boxes
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int R, G, B, N;

ll solve() {
    int ans = 0;
    for (int r = 0; r <= N; r++) {
        for (int g = 0; g <= N; g++) {
            int bB = N - r * R - g * G;
            if (bB >= 0 && bB % B == 0) {
                ans++;
            }
        }
    }

    return ans;
}

int main() {
    cin >> R >> G >> B >> N;

    cout << solve() << endl;

    return 0;
}
