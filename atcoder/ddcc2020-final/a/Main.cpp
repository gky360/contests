/*
[ddcc2020-final] A - Div/de
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 100;
const int MAX_A = 100;

int N;
int A[MAX_N];

bool solve() {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int x = 0;
        for (int d = 2; d * d <= A[i]; d++) {
            while (A[i] % d == 0) {
                x++;
                A[i] /= d;
            }
        }
        if (A[i] > 1) x++;
        ans ^= x;
    }

    return ans != 0;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
