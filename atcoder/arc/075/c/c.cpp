// AtCoder Regular Contest 075
// C - Bugged

#include <cstdio>
#include <algorithm>
#define MAX_N 100
using namespace std;
typedef long long int ll;


int N;
int s[MAX_N];

int main() {

    int ans = 0;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &s[i]);
        ans += s[i];
    }

    if (ans % 10 == 0) {
        sort(s, s + N);
        for (int i = 0; i < N; i++) {
            if (s[i] % 10 != 0) {
                ans -= s[i];
                break;
            }
        }
        if (ans % 10 == 0) {
            ans = 0;
        }
    }

    printf("%d\n", ans);

    return 0;

}



