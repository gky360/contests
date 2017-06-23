// AtCoder Grand Contest 016
// C - +/- Rectangle

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;


int HW[2], hw[2];

int main() {

    int d, k;
    int ij[2];

    cin >> HW[0] >> HW[1] >> hw[0] >> hw[1];

    if (HW[0] % hw[0] != 0) {
        d = 0;
    } else if (HW[1] % hw[1] != 0) {
        d = 1;
    } else {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    k = HW[d] / hw[d] + 1;
    for (ij[0] = 0; ij[0] < HW[0]; ij[0]++) {
        for (ij[1] = 0; ij[1] < HW[1]; ij[1]++) {
            if (ij[d] % hw[d] == 0) {
                cout << k;
            } else if(ij[d] % hw[d] == hw[d] - 1) {
                cout << -k - 1;
            } else {
                cout << 0;
            }
            cout << (ij[1] == HW[1] - 1 ? '\n' : ' ');
        }
    }

    return 0;

}



