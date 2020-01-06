/**
 * Z-Algorithm
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

void z_algorithm(const string &s, vector<int> &ret) {
    int len = s.size();
    ret = vector<int>(len);
    ret[0] = len;
    int i = 1, j = 0;
    while (i < len) {
        while (i + j < len && s[j] == s[i + j]) {
            j++;
        }
        ret[i] = j;
        if (j == 0) {
            i++;
            continue;
        }
        int k;
        for (k = 1; i + k < len && k + ret[k] < j; k++) {
            ret[i + k] = ret[k];
        }
        i += k;
        j -= k;
    }
}

int main() { return 0; }
