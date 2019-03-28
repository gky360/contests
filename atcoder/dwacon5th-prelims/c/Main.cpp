/*
[dwacon5th-prelims] C - k-DMC
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 1e6;
const int C = 3;
const char m[C] = {'D', 'M', 'C'};

int N;
string S;
int Q;

ll solve(int k) {
    ll ans = 0;
    ll cnt_d = 0, cnt_m = 0, cnt_dm = 0;
    for (int i = 0; i < N; i++) {
        if (i - k >= 0) {
            if (S[i - k] == 'M') {
                cnt_m--;
            } else if (S[i - k] == 'D') {
                cnt_d--;
                cnt_dm -= cnt_m;
            }
        }
        if (S[i] == 'C') {
            ans += cnt_dm;
        } else if (S[i] == 'M') {
            cnt_m++;
            cnt_dm += cnt_d;
        } else if (S[i] == 'D') {
            cnt_d++;
        }
    }

    return ans;
}

int main() {
    cin >> N;
    cin >> S;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int k;
        cin >> k;
        cout << solve(k) << endl;
    }

    return 0;
}
