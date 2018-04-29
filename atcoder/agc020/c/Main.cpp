// AGC020
// C - Median Sum

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 2000;
const int MAX_A = 2000;

int N;

int main() {
    cin >> N;
    int s = 0;
    bitset<MAX_N * MAX_A + 1> b;
    b[0] = true;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        s += a;
        b |= b << a;
    }

    int ans;
    for (int i = (s + 1) / 2; i <= s; i++) {
        if (b[i]) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
