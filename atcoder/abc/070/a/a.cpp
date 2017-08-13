// AtCoder Beginner Contest 070
// A - Palindromic Number

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


int N;

int main() {

    cin >> N;

    cout << ((N / 100 == N % 10) ? "Yes" : "No") << endl;

    return 0;

}



