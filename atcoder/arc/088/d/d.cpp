// AtCoder Regular Contest 088
// D - Wide Flip

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

string S;
int N;

int main() {
    int ans;

    cin >> S;
    N = S.length();

    ans = N;
    for (int i = 0; i < N - 1; i++) {
        if (S[i] != S[i + 1]) {
            ans = min(ans, max(i + 1, N - i - 1));
        }
    }

    cout << ans << endl;

    return 0;
}
