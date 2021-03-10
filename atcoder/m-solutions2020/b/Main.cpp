/*
[m-solutions2020] B - Magic 2
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double DD;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(c) (c).begin(), (c).end()

int A, B, C;
int K;

bool solve() {
    int cnt = 0;
    for (; B <= A; B *= 2) cnt++;
    for (; C <= B; C *= 2) cnt++;

    return cnt <= K;
}

int main() {
    cin >> A >> B >> C;
    cin >> K;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
