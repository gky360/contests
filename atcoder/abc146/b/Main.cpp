/*
[abc146] B - ROT N
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int AZ = 26;

int N;
string S;

string solve() {
    for (int i = 0; i < (int)S.size(); i++) {
        S[i] = 'A' + ((S[i] - 'A') + N) % AZ;
    }

    return S;
}

int main() {
    cin >> N;
    cin >> S;

    cout << solve() << endl;

    return 0;
}
