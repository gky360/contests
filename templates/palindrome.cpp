// palindrome

#include <bits/stdc++.h>
using namespace std;


/**
 * @param (str) string consists of any chars except '^', '$' and '_'.
 * @param (res) a vector to which the function will return result.
 *      res[i] is the length of the longest parindrome whose center is str[i * 0.5 - 1]
 * @detail
 * ex.:
 *   str: abracadabra
 *            a   b   r   a   c   a   d   a   b   r   a
 *   res: 0 0 1 0 1 0 1 0 1 0 3 0 1 0 3 0 1 0 1 0 1 0 1 0 0
 */
void manachar(const string &str, vector<int> &res) {
    string s(str.size() * 2 + 3, '_');
    int d;

    s[0] = '^';
    s[str.size() * 2 + 2] = '$';
    for (int i = 0; i < (int)str.size(); i++) {
        s[2 * i + 2] = str[i];
    }

    res.clear();
    res.resize(s.size(), 0);
    for (int c = 1; c < (int)s.size() - 1; c += d) {
        while (s[c - res[c] - 1] == s[c + res[c] + 1]) {
            res[c]++;
        }
        for (d = 1; d <= res[c]; d++) {
            if (res[c - d] == res[c] - d) {
                res[c + d] = res[c] - d;
                break;
            }
            res[c + d] = min(res[c] - d, res[c - d]);
        }
    }

    return;
}


int main() {

    string s;
    vector<int> cr;

    cin >> s;

    manachar(s, cr);
    for (int r : cr) {
        cout << r << ' ';
    }
    cout << endl;

    return 0;
}

