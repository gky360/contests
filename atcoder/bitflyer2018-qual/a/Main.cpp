/*
[bitflyer2018-qual] A - 本選参加者数
*/

#include <algorithm>
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

int A, B;

int solve() { return A / B * B; }

int main() {
    cin >> A >> B;

    cout << solve() << endl;

    return 0;
}
