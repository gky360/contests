/*
[abc124] D - Handstand
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int N, K;
string S;

ll solve() {
    vector<pii> seq;
    int prev = 0;
    if (S[0] == '0') {
        seq.push_back({0, 0});
    }
    for (int i = 1; i < N; i++) {
        if (S[i - 1] == '0' && S[i] == '1') {
            prev = i;
        } else if (S[i - 1] == '1' && S[i] == '0') {
            seq.push_back({prev, i});
        }
    }
    if (S[N - 1] == '0') {
        seq.push_back({N, N});
    } else {
        seq.push_back({prev, N});
    }

    if ((int)seq.size() < K + 1) {
        return N;
    }

    int ans = 0;
    for (int i = 0; i + K < (int)seq.size(); i++) {
        ans = max(ans, seq[i + K].second - seq[i].first);
    }
    return ans;
}

int main() {
    cin >> N >> K;
    cin >> S;

    cout << solve() << endl;

    return 0;
}
