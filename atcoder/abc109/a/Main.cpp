// ARC109
// A - ABC333

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int A, B;

bool solve() { return (A * B) % 2 == 1; }

int main() {
    cin >> A >> B;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
