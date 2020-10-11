/*
[abc157] B - Bingo
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 10;

int A[3][3];
int N;
int b[MAX_N];

bool solve() {
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (A[i][j] == b[k]) {
                    A[i][j] = -1;
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        if (A[i][0] == -1 && A[i][1] == -1 && A[i][2] == -1) {
            return true;
        }
    }
    for (int j = 0; j < 3; j++) {
        if (A[0][j] == -1 && A[1][j] == -1 && A[2][j] == -1) {
            return true;
        }
    }

    return (A[0][0] == -1 && A[1][1] == -1 && A[2][2] == -1) ||
           (A[2][0] == -1 && A[1][1] == -1 && A[0][2] == -1);
}

int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }
    cin >> N;
    for (int k = 0; k < N; k++) {
        cin >> b[k];
    }

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
