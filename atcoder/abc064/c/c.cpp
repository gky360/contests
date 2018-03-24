// AtCoder Beginner Contest 064
// C - Colorful Leaderboard

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long int ll;

const int R = 8;
const int R_STEP = 400;

int N;
int counts[R + 1];

int main() {

    int a;
    int rates;

    scanf("%d", &N);
    memset(counts, 0, sizeof(counts));
    for (int i = 0; i < N; i++) {
        scanf("%d", &a);
        if (a >= R * R_STEP) {
            counts[R]++;
        } else {
            for (int j = 0; j < R; j++) {
                if (a < (j + 1) * R_STEP) {
                    counts[j]++;
                    break;
                }
            }
        }
    }

    rates = 0;
    for (int j = 0; j < R; j++) {
        if (counts[j] > 0) {
            rates++;
        }
    }
    printf("%d %d\n", max(rates, 1), rates + counts[R]);

    return 0;

}



