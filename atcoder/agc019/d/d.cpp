// AtCoder Grand Contest 019
// D - Shift and Flip

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 2000;

int N;
bitset<MAX_N + 1> A, B;

int solve() {
    if (B.none()) {
        if (A.none()) {
            return 0;
        }
        return -1;
    }

    int ret = 2 * N;
    bitset<MAX_N + 1> b = B, mask = B, remain;
    for (int d = 0; d <= N; d++) {
        vector<int> li(N), ri(N);

        li[N - 1] = N - 1;
        while (!mask[li[N - 1] % N]) {
            li[N - 1]++;
        }
        for (int i = N - 2; i >= 0; i--) {
            li[i] = mask[i] ? i : li[i + 1];
        }

        ri[0] = 0;
        while (!mask[(ri[0] + N) % N]) {
            ri[0]--;
        }
        for (int i = 1; i < N; i++) {
            ri[i] = mask[i] ? i : ri[i - 1];
        }

        vector<pii> xys;
        xys.push_back(pii(0, 0));
        remain = (A ^ b) & (~mask);
        for (int i = 0; i < N; i++) {
            if (remain[i]) {
                xys.push_back(pii(li[i] - i, i - ri[i]));
            }
        }
        sort(xys.begin(), xys.end());

        vector<int> y_max(xys.size() + 1);
        y_max[xys.size()] = 0;
        for (int i = xys.size() - 1; i >= 0; i--) {
            y_max[i] = max(y_max[i + 1], xys[i].second);
        }
        int k = N;
        for (int i = 0; i < (int)xys.size(); i++) {
            k = min(k, xys[i].first + y_max[i + 1]);
        }
        ret = min(ret, d + 2 * k + (int)(A ^ b).count());

        b <<= 1;
        b[0] = b[N];
        b[N] = 0;
        mask |= b;
    }

    return ret;
}

void rev(bitset<MAX_N + 1> &a) {
    string tmp = a.to_string().substr(MAX_N + 1 - N);
    reverse(tmp.begin(), tmp.end());
    a = bitset<MAX_N + 1>(tmp);
}

int main() {
    string tmp;
    cin >> tmp;
    A = bitset<MAX_N + 1>(tmp);
    cin >> tmp;
    B = bitset<MAX_N + 1>(tmp);
    N = tmp.size();

    int ans = solve();
    rev(A);
    rev(B);
    ans = min(ans, solve());

    cout << ans << endl;

    return 0;
}
