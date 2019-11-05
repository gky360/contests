/*
[abc126] A - Changing a Character
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int N, K;
string S;

string solve() {
    S[K - 1] += 'a' - 'A';
    return S;
}

int main() {
    cin >> N >> K;
    cin >> S;

    cout << solve() << endl;

    return 0;
}
