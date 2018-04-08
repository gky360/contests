// ARC086
// D - Non-decreasing

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 50;
const int MAX_A = 1e6;

int N;
int a[MAX_N];

int main() {
    cin >> N;
    int min_a = MAX_A, max_a = -MAX_A;
    int min_i, max_i;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (a[i] < min_a) {
            min_a = a[i];
            min_i = i;
        }
        if (a[i] > max_a) {
            max_a = a[i];
            max_i = i;
        }
    }

    bool inv = abs(min_a) > abs(max_a);
    vector<pii> ans;
    for (int i = 0; i < N; i++) {
        if (inv && a[i] > 0) {
            ans.push_back(pii(min_i + 1, i + 1));
        } else if (!inv && a[i] < 0) {
            ans.push_back(pii(max_i + 1, i + 1));
        }
    }

    if (inv) {
        for (int i = N - 1; i > 0; i--) {
            ans.push_back(pii(i + 1, i));
        }
    } else {
        for (int i = 1; i < N; i++) {
            ans.push_back(pii(i, i + 1));
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}
