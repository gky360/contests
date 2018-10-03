// ABC109
// B - Shiritori

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 100;

int N;
string w[MAX_N];

bool solve() {
    unordered_set<string> s;
    s.insert(w[0]);
    for (int i = 1; i < N; i++) {
        if (w[i - 1].back() != w[i][0]) {
            return false;
        }
        if (s.count(w[i]) > 0) {
            return false;
        }
        s.insert(w[i]);
    }
    return true;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> w[i];
    }

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
