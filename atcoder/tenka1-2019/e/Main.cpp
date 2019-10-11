/*
[tenka1-2019] E - Polynomial Divisors
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e4;
const int MAX_P = 1e5;

int N;
vector<int> A;
vector<int> primes;

ll gcd(ll a, ll b) {
    while (b > 0) {
        swap(b, a %= b);
    }
    return a;
}

bool can(int p) {
    vector<int> a = A;
    for (int i = N - p; i >= 0; i--) {
        a[i + 1] += a[i + p];
        a[i + p] = 0;
    }
    return all_of(a.begin(), a.end(), [=](int i) { return i % p == 0; });
}

void solve() {
    bool is_prime[MAX_P + 1];
    fill(is_prime, is_prime + MAX_P + 1, true);
    for (int p = 2; p <= MAX_P; p++) {
        if (!is_prime[p]) {
            continue;
        }
        primes.push_back(p);
        for (int i = p * 2; i <= MAX_P; i += p) {
            is_prime[i] = false;
        }
    }

    int g = 0;
    for (int i = 0; i <= N; i++) {
        g = gcd(g, abs(A[i]));
    }
    for (int p : primes) {
        while (g % p == 0) {
            g /= p;
        }
    }
    if (g != 1) {
        primes.push_back(g);
    }

    for (int p : primes) {
        if (can(p)) {
            cout << p << endl;
        }
    }
}

int main() {
    cin >> N;
    A.resize(N + 1);
    for (int i = N; i >= 0; i--) {
        cin >> A[i];
    }

    solve();

    return 0;
}
