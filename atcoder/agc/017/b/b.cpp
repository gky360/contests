// AtCoder Grand Contest 017
// B - Moderate Differences

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;


int N;
ll A, B, C, D;


bool can() {
    for (int k = 0; k < N; k++) {
        if (k * C - (N - k - 1) * D <= B - A && B - A <= k * D - (N - k - 1) * C) {
            return true;
        }
    }
    return false;
}

int main() {

    cin >> N;
    cin >> A >> B >> C >> D;

    cout << (can() ? "YES" : "NO") << endl;

    return 0;

}



