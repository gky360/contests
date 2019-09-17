/*
[exawizards2019] B - Red or Blue
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int N;
string s;

bool solve() {
    int cnt_r = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] == 'R') {
            cnt_r++;
        }
    }

    return cnt_r > (N - cnt_r);
}

int main() {
    cin >> N;
    cin >> s;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
