// AtCoder Grand Contest 015
// B - Evilator

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;


string S;

int main() {

    ll ans;

    cin >> S;

    ans = (ll)S.length() * ((ll)S.length() - 1);
    for (int i = 1; i < (int)S.length() - 1; i++) {
        ans += (S[i] == 'U') ? i : S.length() - i - 1;
    }

    cout << ans << endl;

    return 0;

}



