// CODE FESTIVAL 2017 qual A
// B - fLIP

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


int N, M, K;

bool can() {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (i * M + j * N - 2 * i * j == K) {
                return true;
            }
        }
    }
    return false;
}

int main() {

    cin >> N >> M >> K;

    cout << (can() ? "Yes" : "No") << endl;

    return 0;

}
