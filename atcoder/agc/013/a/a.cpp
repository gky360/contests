// AtCoder Grand Contest 013
// A - Sorted Arrays

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


int N;

int main() {

    int pre_a, a;
    int ud;
    int ans;

    cin >> N;
    cin >> a;
    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }
    ud = 0;
    ans = 1;
    for (int i = 1; i < N; i++) {
        pre_a = a;
        cin >> a;
        if (ud == 0) {
            ud = a - pre_a;
        } else if ((ud > 0 && a - pre_a < 0) || (ud < 0 && a - pre_a > 0)) {
            ans++;
            ud = 0;
        }
    }

    cout << ans << endl;

    return 0;

}



