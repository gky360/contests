// AtCoder Beginner Contest 064
// B - Traveling AtCoDeer Problem

#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int ll;


int N;
int min_a, max_a;

int main() {

    int a;

    scanf("%d", &N);
    min_a = 1000;
    max_a = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &a);
        min_a = min(min_a, a);
        max_a = max(max_a, a);
    }

    printf("%d\n", max_a - min_a);

    return 0;

}



