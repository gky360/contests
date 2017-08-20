// AtCoder Regular Contest 081
// C - Make a Rectangle

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int MAX_N = 100000;

int N;
priority_queue<ll> q;

int main() {

    int edges;
    ll a;
    ll ans;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        q.push(a);
    }

    edges = 0;
    ans = 0;
    while(q.size() > 1) {
        a = q.top(); q.pop();
        if (a == q.top()) {
            if (edges == 0) {
                ans = a;
            } else if (edges == 1) {
                ans *= a;
                break;
            }
            edges++;
            q.pop();
        }
    }

    cout << ans << endl;

    return 0;

}



