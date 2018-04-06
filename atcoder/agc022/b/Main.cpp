// AGC022
// B - GCD Sequence

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_A = 30000;
const int M = 8;

int N;

int main() {
    vector<int> pat;

    cin >> N;

    if (N == 3) {
        cout << "2 5 63" << endl;
        return 0;
    } else if (N % 2 == 0) {
        pat = {2, 4, 3, 9, 8, 10, 6, 12};
    } else {
        pat = {6, 2, 4, 3, 9, 8, 10, 12};
    }

    for (int i = 0; i < N; i++) {
        cout << pat[i % M] + i / M * 12;
        cout << (i == N - 1 ? '\n' : ' ');
    }

    return 0;
}
