/*
[abc161] B - Popular Vote
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double DD;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 100;

int N, M;
int A[MAX_N];

bool solve() {
    int s = 0;
    for (int i = 0; i < N; i++) {
        s += A[i];
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] * 4 * M >= s) cnt++;
    }

    return cnt >= M;
    ;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
