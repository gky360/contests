// AtCoder Regular Contest 077
// C - pushpush

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;


const int MAX_N = 200000;

int N;
int a[MAX_N];

int main() {

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < N; i++) {
        if (i <= (N - 1) / 2) {
            cout << a[N - 2 * i - 1] << ' ';
        } else {
            cout << a[2 * i - N] << (i == N - 1 ? '\n' : ' ');
        }
    }
    cout << endl;

    return 0;

}



