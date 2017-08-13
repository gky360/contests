// AtCoder Beginner Contest 070
// B - Two Switches

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


int A, B, C, D;

int main() {

    int st, ed;

    cin >> A >> B >> C >> D;

    st = max(A, C);
    ed = min(B, D);

    cout << max(0, ed - st) << endl;

    return 0;

}



