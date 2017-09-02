// AtCoder Grand Contest 019
// B - Reverse and Compare

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int AZ = 26;

string A;
int N;
int cnt[AZ];

int main() {

    ll ans;

    cin >> A;
    N = A.size();
    memset(cnt, 0, sizeof(AZ));
    for (int i = 0; i < N; i++) {
        cnt[A[i] - 'a']++;
    }

    ans = (ll)N * (N - 1LL) / 2LL + 1;
    for (int i = 0; i < AZ; i++) {
        if (cnt[i] < 2) {
            continue;
        }
        ans -= (ll)cnt[i] * (cnt[i] - 1LL) / 2LL;
    }

    cout << ans << endl;

    return 0;

}

