// ARC083
// C - Sugar Water

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int A, B, C, D, E, F;

int main() {
    cin >> A >> B >> C >> D >> E >> F;

    int ans_w, ans_s;
    double max_p = 0.0;
    for (int a = 0; a <= F / (100 * A); a++) {
        for (int b = 0; b <= F / (100 * B); b++) {
            int w = 100 * (A * a + B * b);
            if (w == 0) {
                continue;
            }
            int s_max = min(F - w, w / 100 * E);
            for (int c = 0; c * C <= s_max; c++) {
                for (int d = 0; c * C + d * D <= s_max; d++) {
                    int s = c * C + d * D;
                    double p = 100.0 * s / (w + s);
                    if (p >= max_p) {
                        max_p = p;
                        ans_w = w;
                        ans_s = s;
                    }
                }
            }
        }
    }

    cout << (ans_w + ans_s) << " " << ans_s << endl;

    return 0;
}
