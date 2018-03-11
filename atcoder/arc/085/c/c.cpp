// ARC085
// C - HSI

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int T_1 = 1900;
const int T_2 = 100;

int N, M;

int main() {
    cin >> N >> M;

    int t = T_1 * M + T_2 * (N - M);

    cout << t * pow(2, M) << endl;

    return 0;
}
