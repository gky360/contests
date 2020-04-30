/*
[arc100] C - Linear Approximation
*/

#include <algorithm>
#include <iostream>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 200000;

int N;
int A[MAX_N];

ll solve() {
    int b[MAX_N];
    for (int i = 0; i < N; i++) {
        b[i] = A[i] - i + 1;
    }
    sort(b, b + N);

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += abs(b[i] - b[N / 2]);
    }
    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
