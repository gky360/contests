// AGC025
// A - Digits Sum

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 100000;

int N;

int solve() {
    int sum = 0;
    for (; N > 0; N /= 10) {
        sum += N % 10;
    }
    if (sum == 1) {
        return 10;
    }
    return sum;
}

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
