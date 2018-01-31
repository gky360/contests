// CODE FESTIVAL 2017 qual A
// C - Palindromic Matrix

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int AZ = 26;

int H, W;
int cnt[AZ];

bool can() {
    int c1 = 0;
    int c2 = 0;
    int c4 = 0;
    int odd_k = 0;

    for (int k = 0; k < AZ; k++) {
        if (cnt[k] % 2 == 1) {
            c1++;
            odd_k = k;
        } else if (cnt[k] % 4 == 2) {
            c2++;
        } else {
            c4++;
        }
    }

    if (H % 2 == 1 && W % 2 == 1) {
        if (c1 >= 2) {
            return false;
        }
        if (c1 == 1) {
            c1--;
            if ((cnt[odd_k] - 1) % 4 == 2) {
                c2++;
            } else {
                c4++;
            }
        }
    }

    if (H % 2 == 0 && W % 2 == 0) {
        return c4 == H * W;
    } else if (H % 2 == 1) {
        return c1 == 0 && c2 <= H - 1;
    }
    return c1 == 0 && c2 <= W - 1;
}

int main() {

    string tmp;
    cin >> H >> W;

    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < H; i++) {
        cin >> tmp;
        for (int j = 0; j < W; j++) {
            cnt[tmp[j] - 'a']++;
        }
    }

    cout << (can() ? "Yes" : "No") << endl;

    return 0;

}
