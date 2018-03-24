// AtCoder Regular Contest 080
// E - Young Maids

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, pii> piii;


const int MAX_N = 200000;
const int INF = (int)1e8;

template <typename T>
class RMQ {
public:
    int n;
    vector<T> dat;
    void init(int _n);
    void update(int k, T a);
    T query(int a, int b);
private:
    T query(int a, int b, int k, int l, int r);
};

template <typename T>
void RMQ<T>::init(int _n) {
    n = 1;
    while (n < _n) {
        n <<= 1;
    }
    dat.reserve(2 * n - 1);
    for (int i = 0; i < 2 * n - 1; i++) {
        dat[i] = INF;
    }
    return;
}

template <typename T>
void RMQ<T>::update(int k, T a) {
    k += n - 1;
    dat[k] = a;
    while (k > 0) {
        k = (k - 1) / 2;
        dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
    return;
}

template <typename T>
T RMQ<T>::query(int a, int b) {
    return query(a, b, 0, 0, n);
}

// [a, b), [l, r)
template <typename T>
T RMQ<T>::query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) {
        return INF;
    }
    if (a <= l && r <= b) {
        return dat[k];
    }
    return min(query(a, b, k * 2 + 1, l, (l + r) / 2), query(a, b, k * 2 + 2, (l + r) / 2, r));
}


int N;
int p[MAX_N];
int at[MAX_N + 1];
RMQ<int> st[2];
priority_queue<piii, vector<piii>, greater<piii>> q;
vector<int> ans;

int main() {

    int l, r, a, b, av, bv;

    cin >> N;
    st[0].init(N / 2);
    st[1].init(N / 2);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
        at[p[i]] = i;
        st[i % 2].update(i / 2, p[i]);
    }

    q.push(piii(st[0].query(0, N / 2), pii(0, N)));
    while (!q.empty()) {
        piii sec = q.top(); q.pop();
        l = sec.second.first;
        r = sec.second.second;
        if (l >= r) {
            continue;
        }
        av = sec.first;
        a = at[av];
        bv = st[(l + 1) % 2].query((a + 1) / 2, (r + 1) / 2);
        b = at[bv];
        ans.push_back(av); ans.push_back(bv);
        q.push(piii(st[l % 2].query(l / 2, a / 2), pii(l, a)));
        q.push(piii(st[(a + 1) % 2].query((a + 1) / 2, b / 2), pii(a + 1, b)));
        q.push(piii(st[(b + 1) % 2].query((b + 1) / 2, r / 2), pii(b + 1, r)));
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << (i == N - 1 ? '\n' : ' ');
    }

    return 0;

}



