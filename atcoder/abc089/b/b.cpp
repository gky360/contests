// ARC089
// B - Hina Arare

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int N;

int main() {
    string s;
    bool isFour = false;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s;
        if (s == "Y") {
            isFour = true;
        }
    }

    cout << (isFour ? "Four" : "Three") << endl;

    return 0;
}
