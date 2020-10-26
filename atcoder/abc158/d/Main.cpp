/*
[abc158] D - String Formation
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

string S;

string solve() {
    deque<char> s;
    for (char c : S) {
        s.push_back(c);
    }

    bool rev = false;

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int T;
        cin >> T;
        if (T == 1) {
            rev = !rev;
        } else {
            int F;
            char C;
            cin >> F >> C;

            if ((!rev && F == 1) || (rev && F == 2)) {
                s.push_front(C);
            } else {
                s.push_back(C);
            }
        }
    }

    string ans;
    while (!s.empty()) {
        char c = s.front();
        s.pop_front();
        ans.push_back(c);
    }
    if (rev) {
        reverse(ALL(ans));
    }
    return ans;
}

int main() {
    cin >> S;

    cout << solve() << endl;

    return 0;
}
