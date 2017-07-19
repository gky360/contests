// AtCoder Grand Contest 010
// A - Addition

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


int N;

int main() {

    int a;
    int ans;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        ans += a % 2;
    }
    cout << (ans % 2 == 0 ? "YES" : "NO") << endl;

    return 0;

}
