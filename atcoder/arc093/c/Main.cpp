// ARC093
// C - Traveling Plan

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 100000;

int N;
vector<int> a;

int main() {
    vector<int> a_s;

    cin >> N;
    a.resize(N + 2);
    a[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    a[N + 1] = 0;

    int s = 0;
    for (int i = 1; i < N + 2; i++) {
        s += abs(a[i - 1] - a[i]);
    }

    for (int i = 1; i <= N; i++) {
        cout << s - abs(a[i - 1] - a[i]) - abs(a[i] - a[i + 1]) +
                    abs(a[i - 1] - a[i + 1])
             << endl;
    }

    return 0;
}
