/*
[agc024] B - Backfront
*/

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 200000;

int N;
int p[MAX_N];
int pos[MAX_N];

int solve() {
    for (int i = 0; i < N; i++) {
        pos[p[i]] = i;
    }

    int ans = N;
    int cnt = 1;
    for (int i = 1; i < N; i++) {
        if (pos[i] > pos[i - 1]) {
            cnt++;
        } else {
            ans = min(ans, N - cnt);
            cnt = 1;
        }
    }
    ans = min(ans, N - cnt);
    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> p[i];
        p[i]--;
    }

    cout << solve() << endl;

    return 0;
}
