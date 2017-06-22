// AtCoder Grand Contest 016
// B - Colorful Hats

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

const int MAX_N = 100000;

int N;
int a[MAX_N];


bool can(int min_a, int max_a, int k) {
    if (max_a - min_a > 1) {
        return false;
    }

    bool res = (max_a > k) && ((max_a - k) * 2 <= N - k);
    res = res || (min_a == max_a && k == 0 && (min_a + 1) == N);
    return res;
}

int main() {

    int min_a, max_a;
    int cnt;

    cin >> N;
    min_a = N;
    max_a = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (a[i] > max_a) {
            cnt = 1;
            max_a = a[i];
        } else if (a[i] == max_a) {
            cnt++;
        }
        min_a = min(min_a, a[i]);
    }

    cout << (can(min_a, max_a, N - cnt) ? "Yes" : "No") << endl;

    return 0;

}



