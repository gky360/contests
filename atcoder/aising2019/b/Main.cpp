/*
[aising2019] B - Contests
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 100;

int N;
int A, B;
int P[MAX_N];
int cnt[3];

ll solve() {
    for (int i = 0; i < N; i++) {
        if (P[i] <= A) {
            cnt[0]++;
        } else if (P[i] <= B) {
            cnt[1]++;
        } else {
            cnt[2]++;
        }
    }

    return min(min(cnt[0], cnt[1]), cnt[2]);
}

int main() {
    cin >> N;
    cin >> A >> B;
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    cout << solve() << endl;

    return 0;
}
