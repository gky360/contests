// AtCoder Grand Contest 018
// C - Coins

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int MAX_N = 100000;

struct person {
    ll x, y, z;
};

int N;
int X, Y, Z;
person p[MAX_N];
ll ms[2][MAX_N + 1];

int main() {

    auto comp0 = [](person p1, person p2) { return (p1.y - p1.z) > (p2.y - p2.z); };
    auto comp1 = [](person p1, person p2) { return (p1.x - p1.z) > (p2.x - p2.z); };
    priority_queue<person, vector<person>, decltype(comp0)> q0(comp0);
    priority_queue<person, vector<person>, decltype(comp1)> q1(comp1);
    ll ans;

    cin >> X >> Y >> Z;
    N = X + Y + Z;
    for (int i = 0; i < N; i++) {
        cin >> p[i].x >> p[i].y >> p[i].z;
    }
    sort(p, p + N, [](person p1, person p2) { return (p1.x - p1.y) < (p2.x - p2.y); });

    ms[0][Y] = 0;
    for (int i = 0; i < Y; i++) {
        q0.push(p[i]);
        ms[0][Y] += p[i].y;
    }
    for (int k = Y; k < Y + Z; k++) {
        q0.push(p[k]);
        ms[0][k + 1] = ms[0][k] + p[k].y;
        person pr = q0.top(); q0.pop();
        ms[0][k + 1] += -pr.y + pr.z;
    }
    ms[1][Y + Z] = 0;
    for (int i = N - 1; i >= Y + Z; i--) {
        q1.push(p[i]);
        ms[1][Y + Z] += p[i].x;
    }
    for (int k = Y + Z - 1; k >= Y; k--) {
        q1.push(p[k]);
        ms[1][k] = ms[1][k + 1] + p[k].x;
        person pr = q1.top(); q1.pop();
        ms[1][k] += -pr.x + pr.z;
    }

    ans = 0;
    for (int k = Y; k <= Y + Z; k++) {
        ans = max(ans, ms[0][k] + ms[1][k]);
    }
    cout << ans << endl;

    return 0;

}



