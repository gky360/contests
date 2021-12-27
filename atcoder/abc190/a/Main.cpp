/*
[abc190] A - Very Very Primitive Game
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double DD;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(c) (c).begin(), (c).end()


int A, B,C;

bool solve() {


    return A + C > B;
}

int main() {
    cin>>A>>B>>C;


    cout << (solve() ? "Takahashi" : "Aoki") << endl;

    return 0;

}
