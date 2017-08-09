// AtCoder Regular Contest 080
// C - 4-adjacent

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


int N;

bool can(int cnt4, int cnt2) {
    if (cnt4 >= N / 2) {
        return true;
    }
    return (cnt4 * 2 + (cnt2 - cnt4) >= N);
}

int main() {

    int a;
    int cnt4, cnt2;

    cin >> N;
    cnt4 = cnt2 = 0;
    for (int i = 0; i < N; i++) {
        cin >> a;
        cnt4 += (a % 4 == 0 ? 1 : 0);
        cnt2 += (a % 2 == 0 ? 1 : 0);
    }

    cout << (can(cnt4, cnt2) ? "Yes" : "No") << endl;

    return 0;

}



