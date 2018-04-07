// ARC086
// C - Not so Diverse

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int K, N;

int main() {
    cin >> N >> K;

    vector<int> cnt(N + 1);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    sort(cnt.begin(), cnt.end());

    int ans = 0;
    for (int i = 0; i < N + 1 - K; i++) {
        ans += cnt[i];
    }

    cout << ans << endl;

    return 0;
}
