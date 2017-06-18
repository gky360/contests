// AtCoder Beginner Contest 064
// A - RGB Cards

#include <cstdio>

using namespace std;
typedef long long int ll;


int main() {

    int r, g, b;

    scanf("%d%d%d", &r, &g, &b);

    printf("%s\n", (r * 100 + g * 10 + b) % 4 == 0 ? "YES" : "NO");

    return 0;

}



