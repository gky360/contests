// AtCoder Grand Contest 019
// A - Ice Tea Store

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


ll Q, H, S, D;
ll N;

int main() {

    ll l1, l2;

    cin >> Q >> H >> S >> D;
    cin >> N;

    l1 = min(Q * 4, H * 2);
    l1 = min(l1, S);
    l2 = min(l1 * 2, D);

    cout << (N / 2 * l2) + (N % 2 * l1) << endl;

    return 0;

}
