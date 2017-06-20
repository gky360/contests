// AtCoder Beginner Contest 064
// D - Insertion

#include <iostream>

using namespace std;
typedef long long int ll;


int N;
string S;
int depth;

int main() {

    cin >> N;
    cin >> S;

    depth = 0;
    for (char &c : S) {
        if (c == '(') {
            depth++;
        } else {
            if (depth == 0) {
                cout << '(';
            } else {
                depth--;
            }
        }
    }
    cout << S;
    for (int i = 0; i < depth; i++) {
        cout << ')';
    }
    cout << endl;

    return 0;

}



