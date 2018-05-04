// AGC021
// B - Holes

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 100;
constexpr double PI = atan(1) * 4;

int N;
pii xy[MAX_N];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> xy[i].first >> xy[i].second;
    }

    for (int i = 0; i < N; i++) {
        vector<double> slopes;
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            int dx = xy[j].first - xy[i].first;
            int dy = xy[j].second - xy[i].second;
            slopes.push_back(atan2(dy, dx));
        }
        sort(slopes.begin(), slopes.end());
        slopes.push_back(slopes[0] + 2 * PI);

        double ans = 0.0;
        for (int i = 0; i < N; i++) {
            if (slopes[i + 1] - slopes[i] >= PI) {
                ans = (slopes[i + 1] - slopes[i] - PI) / (2 * PI);
                break;
            }
        }
        cout << fixed << setprecision(8) << ans << endl;
    }

    return 0;
}
