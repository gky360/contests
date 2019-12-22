/*
[abc148] B - Strings with the Same Length
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int N;
string S, T;

string solve() {
    string ans;
    for (int i = 0; i < N; i++) {
        ans.push_back(S[i]);
        ans.push_back(T[i]);
    }

    return ans;
}

int main() {
    cin >> N;
    cin >> S >> T;

    cout << solve() << endl;

    return 0;
}
