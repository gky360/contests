// bit operation

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

ll bits_msb(ll v) {
    for (unsigned int i = 1; i < sizeof(v) * 8; i <<= 1) {
        v = v | (v >> i);
    }
    return v ^ (v >> 1);
}

int main() {
    pair<ll, ll> testcases[] = {{0x3587, 0x2000}, {0xffff, 0x8000}};
    for (auto testcase : testcases) {
        ll input = testcase.first;
        ll expected = testcase.second;
        cerr << hex << "bits_msb(0x" << input << ") = 0x" << bits_msb(input)
             << endl;
        assert(bits_msb(input) == expected);
    }
    return 0;
}
