/*
[abc141] E - Who Says a Pun?
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 5e3;

void z_algorithm(const string &s, vector<int> &ret) {
    int len = s.size();
    ret = vector<int>(len);
    ret[0] = len;
    int i = 1, j = 0;
    while (i < len) {
        while (i + j < len && s[j] == s[i + j]) {
            j++;
        }
        ret[i] = j;
        if (j == 0) {
            i++;
            continue;
        }
        int k;
        for (k = 1; i + k < len && k + ret[k] < j; k++) {
            ret[i + k] = ret[k];
        }
        i += k;
        j -= k;
    }
}

int N;
string S;

ll solve() {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        vector<int> z;
        z_algorithm(S.substr(i), z);
        for (int i = 1; i < (int)z.size(); i++) {
            ans = max(ans, min(z[i], i));
        }
    }

    return ans;
}

int main() {
    cin >> N;
    cin >> S;

    cout << solve() << endl;

    return 0;
}
