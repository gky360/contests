/*
[abc104] C - All Green
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

const int MAX_D = 10;
const int MAX_P = 100;

int D, G;
int p[MAX_D], c[MAX_D];

ll solve() {
    int ans = MAX_D * MAX_P;
    for (int pat = 0; pat < (1 << D); pat++) {
        int score = 0;
        int questions = 0;
        int last_incomplete = -1;
        for (int i = 0; i < D; i++) {
            if (pat & (1 << i)) {
                score += 100 * (i + 1) * p[i] + c[i];
                questions += p[i];
            } else {
                last_incomplete = i;
            }
        }
        if (score < G) {
            int q = 100 * (last_incomplete + 1);
            int additional_qs = (G - score + q - 1) / q;
            if (additional_qs >= p[last_incomplete]) {
                continue;
            }
            questions += additional_qs;
        }
        ans = min(ans, questions);
    }

    return ans;
}

int main() {
    cin >> D >> G;
    for (int i = 0; i < D; i++) {
        cin >> p[i] >> c[i];
    }

    cout << solve() << endl;

    return 0;
}
