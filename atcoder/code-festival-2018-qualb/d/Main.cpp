/*
[code-festival-2018-qualb] D - Sushi Restaurant
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

const int MAX_N = 2000;
const int MAX_M = 2000;

int N, M, q;
int x[MAX_M], p[MAX_M];
double logi[MAX_N + 1], logfac[MAX_N + 1];
double logspl[MAX_M + 1], logspr[MAX_M + 1];
double u[MAX_N + 1][MAX_M + 1];

double solve() {
    logfac[0] = 0;
    for (int i = 1; i <= N; i++) {
        logi[i] = log(i);
        logfac[i] = logfac[i - 1] + logi[i];
    }

    double sum = 0.0;
    logspl[0] = -1e8;
    logspr[M] = -1e8;
    for (int i = 0; i < M; i++) {
        logspr[i] = log(1.0 - sum);
        sum += 1.0 * p[i] / q;
        logspl[i + 1] = log(sum);
    }

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            u[i][j] = exp(logspl[j] * i + logspr[j] * (N - i) + logfac[N] -
                          logfac[i] - logfac[N - i]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= M; j++) {
            u[i + 1][j] += u[i][j];
        }
    }

    double ans = 0.0;
    for (int i = 0; i < N; i++) {
        double sum = 0.0;
        int center = -1;
        for (int j = 0; j < M; j++) {
            if (sum < 0.5) {
                center = j;
            }
            sum += u[i][j] - u[i][j + 1];
        }
        for (int j = 0; j < M; j++) {
            ans += abs(x[j] - x[center]) * (u[i][j] - u[i][j + 1]);
        }
    }

    return ans;
}

int main() {
    cin >> N >> M >> q;
    for (int i = 0; i < M; i++) {
        cin >> x[i] >> p[i];
    }

    cout << fixed << setprecision(10) << solve() << endl;

    return 0;
}
