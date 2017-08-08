// AtCoder Grand Contest 018
// B - Sports Festival

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int MAX_N = 300;
const int MAX_M = 300;

int N, M;
int a[MAX_N][MAX_M];
bool removed[MAX_M];
int cnt[MAX_M];
int idx[MAX_N];

int main() {

    int mm, mp;
    int ans;

    cin >> N >> M;
    memset(removed, 0, sizeof(removed));
    memset(cnt, 0, sizeof(cnt));
    memset(idx, 0, sizeof(idx));
    mp = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j]; a[i][j]--;
        }
        idx[i] = 0;
        cnt[a[i][idx[i]]]++;
        if (cnt[a[i][idx[i]]] >= mp) {
            mp = cnt[a[i][idx[i]]];
            mm = a[i][idx[i]];
        }
    }
    ans = mp;

    for (int k = 0; k < M - 1; k++) {
        removed[mm] = true;
        for (int i = 0; i < N; i++) {
            cnt[a[i][idx[i]]]--;
            for (int &j = idx[i]; j < M && removed[a[i][j]]; j++) {}
            cnt[a[i][idx[i]]]++;
        }
        mp = 0;
        for (int j = 0; j < M; j++) {
            if (cnt[j] >= mp) {
                mp = cnt[j];
                mm = j;
            }
        }
        ans = min(ans, mp);
    }

    cout << ans << endl;

    return 0;

}




