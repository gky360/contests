// ARC082
// D - Derangement

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 100000;

int N;
int p[MAX_N];

int main() {
    cin >> N;

    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        if (p == i + 1) {
            cnt++;
        } else {
            ans += (cnt + 1) / 2;
            cnt = 0;
        }
    }
    ans += (cnt + 1) / 2;

    cout << ans << endl;

    return 0;
}
