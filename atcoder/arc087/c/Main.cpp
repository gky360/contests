// ARC087
// C - Good Sequence

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int N;
map<int, int> cnt;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }

    int ans = 0;
    for (auto iter : cnt) {
        if (iter.second < iter.first) {
            ans += iter.second;
        } else {
            ans += iter.second - iter.first;
        }
    }

    cout << ans << endl;

    return 0;
}
