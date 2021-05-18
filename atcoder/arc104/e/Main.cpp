/*
[arc104] E - Random LIS
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 6;
const int MOD = 1000000007;

class gf {
public:
    int n;
    static gf mod_inv(int a, int m) {
        int u = 0, v = 1;
        while (a != 0) {
            int t = m / a;
            m -= t * a;
            u -= t * v;
            swap(a, m);
            swap(u, v);
        }
        return gf(u);
    }
    gf() : n(0) {}
    gf(int n) : n(n < 0 ? n % MOD + MOD : n % MOD) {}
    gf operator+(gf x) { return gf((n + x.n) % MOD); }
    gf operator-(gf x) { return gf((n - x.n + MOD) % MOD); }
    gf operator*(gf x) { return gf((1LL * n * x.n) % MOD); }
    gf operator/(gf x) { return *this * x.inv(); }
    gf& operator+=(gf x) { return *this = (*this + x); }
    gf& operator-=(gf x) { return *this = (*this - x); }
    gf& operator*=(gf x) { return *this = (*this * x); }
    gf& operator/=(gf x) { return *this = (*this / x); }
    gf inv() { return mod_inv(n, MOD); }
};

gf combi(ll n, int k) {
    if (n < 0 || k < 0 || n < k) {
        return 0;
    }
    gf ret = 1;
    for (int i = 0; i < k; i++) {
        ret *= n - i;
        ret /= (i + 1);
    }
    return ret;
}

int N;
int A[MAX_N];
vector<int> V;

int lis(vector<int>& x) {
    vector<int> dp(x.size(), *max_element(ALL(x)) + 1);
    int ret = 0;
    for (int n : x) {
        int i = lower_bound(ALL(dp), n) - dp.begin();
        dp[i] = n;
        ret = max(ret, i + 1);
    }
    return ret;
}

gf calc(vector<int>& ord, int e) {
    vector<int> rank, rs;
    for (int i = 0; i < N; i++) {
        if (i - 1 >= 0 && ((e >> (i - 1)) & 1)) {
            *rank.rbegin() = min(*rank.rbegin(), A[ord[i]]);
            (*rs.rbegin())++;
        } else {
            rank.push_back(A[ord[i]]);
            rs.push_back(1);
        }
    }

    vector<int> ord_rank(N);
    int idx = 0;
    for (int i = 0; i < (int)rs.size(); i++) {
        for (int j = 0; j < rs[i]; j++) {
            ord_rank[ord[idx]] = i;
            idx++;
        }
    }

    gf p = 1;
    int sz = 1;
    for (int i = 0; i < N - 1; i++) {
        if ((e >> i) & 1) {
            sz++;
        } else {
            sz = 1;
        }
        p *= sz;
    }

    gf dp[MAX_N + 1][MAX_N + 1];
    dp[0][0] = 1;
    for (int i = 1; i <= (int)rank.size(); i++) {
        for (int j = 1; j <= rank[i - 1]; j++) {
            for (int k = i - 1; k >= 0; k--) {
                for (int l = 0; l < j; l++) {
                    dp[i][j] += dp[k][l] * combi(V[j] - V[j - 1], i - k);
                }
                if (k - 1 >= 0 && rank[k - 1] < j) {
                    break;
                }
            }
        }
    }

    gf cnt = 0;
    for (int j = 0; j <= N; j++) {
        cnt += dp[rank.size()][j];
    }

    gf ret = cnt * lis(ord_rank) / p;
    return ret;
}

ll solve() {
    vector<int> ord(N);
    V.resize(N);
    for (int i = 0; i < N; i++) {
        V[i] = A[i];
        ord[i] = i;
    }
    V.push_back(0);
    sort(ALL(V));
    V.erase(unique(ALL(V)), V.end());
    for (int i = 0; i < N; i++) {
        A[i] = lower_bound(ALL(V), A[i]) - V.begin();
    }

    gf ans = 0;
    do {
        for (int e = 0; e < (1 << (N - 1)); e++) {
            ans += calc(ord, e);
        }
    } while (next_permutation(ALL(ord)));
    for (int i = 0; i < N; i++) {
        ans /= V[A[i]];
    }

    return ans.n;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
