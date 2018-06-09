// ARC100
// E - Or Plus Max

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 18;
const int MAX_K = (1 << MAX_N);

class Elm {
public:
    int x[2];
    Elm() { x[0] = x[1] = 0; };
    Elm(int x0, int x1) {
        x[0] = x0;
        x[1] = x1;
    };
    Elm operator+=(Elm e) {
        int tmp[4] = {x[1], x[0], e.x[1], e.x[0]};
        sort(tmp, tmp + 4);
        x[0] = tmp[3];
        x[1] = tmp[2];
        return *this;
    };
    int sum() { return x[0] + x[1]; };
};

vector<Elm> moebius(vector<Elm> f) {
    // get F(S) = \sum_{T ⊆ S} G(T)
    for (int b = 1; b < (int)f.size(); b <<= 1) {
        for (int i = 0; i < (int)f.size(); i++) {
            if (i & b) {
                f[i] += f[i ^ b];
            }
        }
    }
    return f;
}

int N;

int main() {
    cin >> N;

    vector<Elm> f(MAX_K);
    for (int i = 0; i < (1 << N); i++) {
        int a;
        cin >> a;
        f[i].x[0] = a;
    }
    vector<Elm> g = moebius(f);

    int ans = -1;
    for (int i = 1; i < (1 << N); i++) {
        ans = max(ans, g[i].sum());
        cout << ans << endl;
    }

    return 0;
}
