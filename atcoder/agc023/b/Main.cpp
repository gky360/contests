// AGC023
// B - Find Symmetries

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 300;

int N;
char s[MAX_N][MAX_N + 2];

bool check(int d) {
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            if (s[i][(j + d) % N] != s[j][(i + d) % N]) {
                return false;
            }
        }
    }
    return true;
}

int solve() {
    int ans = 0;
    for (int d = 0; d < N; d++) {
        if (check(d)) {
            ans += N;
        }
    }
    return ans;
}

int main() {
    cin >> N;
    for (int j = 0; j < N; j++) {
        cin >> s[j];
        cerr << s[j] << endl;
    }

    cout << solve() << endl;

    return 0;
}
