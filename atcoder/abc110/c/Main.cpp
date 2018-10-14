/*
[abc110] C - String Transformation
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int AZ = 26;

string s, t;
int N;

bool solve() {
    int s2t[AZ], t2s[AZ];
    memset(s2t, -1, sizeof(s2t));
    memset(t2s, -1, sizeof(t2s));

    for (int i = 0; i < N; i++) {
        int sc = s[i] - 'a', tc = t[i] - 'a';
        if (s2t[sc] == -1) {
            s2t[sc] = tc;
        } else if (s2t[sc] != tc) {
            return false;
        }
        if (t2s[tc] == -1) {
            t2s[tc] = sc;
        } else if (t2s[tc] != sc) {
            return false;
        }
    }

    return true;
}

int main() {
    cin >> s;
    cin >> t;
    N = s.size();

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
