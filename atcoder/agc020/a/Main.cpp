// AGC020
// A - Move and Win

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int N, A, B;

int main() {
    cin >> N >> A >> B;

    cout << ((B - A) % 2 == 0 ? "Alice" : "Borys") << endl;

    return 0;
}
