/*
[ddcc2019-final] A - レース (Race)
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

int N;
string S;

double solve() {
    double sum = 0.0;
    int k = 0;
    int max_k = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '-') {
            sum += 1.0;
            k = 0;
        } else {
            sum += 1.0 / (k + 2.0);
            k++;
            max_k = max(max_k, k);
        }
    }

    return sum - 1.0 + 1.0 / (max_k + 2.0);
}

int main() {
    cin >> N;
    cin >> S;

    cout << setprecision(15) << solve() << endl;

    return 0;
}
