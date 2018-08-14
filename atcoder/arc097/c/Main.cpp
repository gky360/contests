// AtCoder Regular Contest 097
// C - K-th Substring

#include <algorithm>
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

string s;
int K;

string solve() {
    int n = s.size();
    vector<string> ss;
    for (int i = 0; i < n; i++) {
        for (int l = 1; l <= min(K, n - i); l++) {
            ss.push_back(s.substr(i, l));
        }
    }
    sort(ss.begin(), ss.end());
    ss.erase(unique(ss.begin(), ss.end()), ss.end());
    return ss[K - 1];
}

int main() {
    cin >> s;
    cin >> K;

    cout << solve() << endl;

    return 0;
}
