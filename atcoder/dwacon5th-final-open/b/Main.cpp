/*
[dwacon5th-final-open] B - XOR Spread
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 1e5;

class BinaryTrie {
public:
    int cnt;
    BinaryTrie *next[2];
    BinaryTrie() {
        cnt = 0;
        fill(next, next + 2, nullptr);
    }
    void insert(int n, int len = 32) {
        if (len == 0) {
            cnt++;
            return;
        }
        int b = (n >> (len - 1)) & 1;
        if (next[b] == nullptr) {
            next[b] = new BinaryTrie();
        }
        next[b]->insert(n, len - 1);
    }
    int xor_lower_bound(int n, int len = 32) {
        if (len == 0) {
            return 0;
        }
        for (int i = 0, b = (n >> (len - 1)) & 1; i < 2; i++, b = b ^ 1) {
            if (next[b] != nullptr) {
                int ret = next[b]->xor_lower_bound(n, len - 1);
                if (ret != -1) {
                    return ret | (b << (len - 1));
                }
            }
        }
        return -1;
    }
    bool remove(int n, int len = 32) {
        if (len == 0) {
            cnt--;
            return cnt == 0;
        }
        int b = (n >> (len - 1)) & 1;
        if (next[b] != nullptr && next[b]->remove(n, len - 1)) {
            delete next[b];
            next[b] = nullptr;
        }
        return next[0] == nullptr && next[1] == nullptr;
    }
};

int N;
int a[MAX_N];
int b[MAX_N + 1];
BinaryTrie t;

void solve() {
    int b = 0;
    for (int i = 0; i < N - 1; i++) {
        b = b ^ a[i];
        t.insert(b);
    }
    int rb = b ^ a[N - 1];

    b = 0;
    for (int i = 0; i < N - 1; i++) {
        int nb = t.xor_lower_bound(b);
        assert(nb != -1);
        t.remove(nb);
        cout << (nb ^ b) << " ";
        b = nb;
    }
    cout << (b ^ rb) << endl;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    solve();

    return 0;
}
