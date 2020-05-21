/*
[abc141] F - Xor Sum 3
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;
const int MAX_D = 60;

typedef vector<bitset<MAX_D>> Matrix;

void elim(Matrix &A) {
    const int n = A.size(), m = A[0].size();
    int r = 0;
    for (int i = 0; r < n && i < m; ++i) {
        int pivot = r;
        for (int j = r; j < n; ++j) {
            if (A[j][m - i - 1]) {
                pivot = j;
                break;
            }
        }
        swap(A[pivot], A[r]);
        if (A[r][m - i - 1] == 0) {
            continue;
        }
        for (int j = 0; j < n; ++j) {
            if (j != r && A[j][m - i - 1]) {
                A[j] ^= A[r];
            }
        }
        ++r;
    }
}

int N;
Matrix A;

ll solve() {
    bitset<MAX_D> s;

    for (int i = 0; i < N; i++) {
        s ^= A[i];
    }

    for (int i = 0; i < N; i++) {
        A[i] &= ~s;
    }
    elim(A);

    bitset<MAX_D> x;
    for (int i = 0; i < N; i++) {
        x ^= A[i];
    }

    ll ans = (x | s).to_ullong() + x.to_ullong();
    return ans;
}

int main() {
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        A[i] = bitset<MAX_D>(a);
    }

    cout << solve() << endl;

    return 0;
}
