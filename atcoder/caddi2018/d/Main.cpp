/*
[caddi2018] D - Harlequin
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

const int MAX_N = 1e5;

int N;
int a[MAX_N];

bool solve() {
    int x = 0;
    for (int i = 0; i < N; i++) {
        x += a[i] % 2;
    }
    return x != 0;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << (solve() ? "first" : "second") << endl;

    return 0;
}
