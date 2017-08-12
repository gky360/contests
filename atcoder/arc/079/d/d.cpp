// AtCoder Regular Contest 079
// D - Decrease (Contestant ver.)

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const ll MAX_K = (ll)5e17;
const ll MAX_N = 50;

ll K;
ll N;

int main() {

    ll a;

    cin >> K;
    N = MAX_N;
    cout << N << endl;
    for (ll i = 0; i < N; i++) {
        a = N - 1 + K / N;
        if (i < K % N) {
            a += N - K % N + 1;
        } else {
            a -= K % N;
        }
        cout << a << (i == N - 1 ? '\n' : ' ');
    }


    return 0;

}



