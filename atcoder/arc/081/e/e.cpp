// AtCoder Regular Contest 081
// E - Don't Be a Subsequence

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int A2Z = 26;

int N;
string s;
stack<int> st;
vector<int> at[A2Z];

int main() {

    int min_i;
    int idx;
    string ans;

    cin >> s;
    N = s.length();
    for (int i = 0; i < N; i++) {
        at[s[i] - 'a'].push_back(i);
    }

    for (int j = 0; j < A2Z; j++) {
        at[j].push_back(N);
    }

    min_i = N;
    while (min_i >= 0) {
        st.push(min_i);
        for (int j = 0; j < A2Z; j++) {
            auto itr = lower_bound(at[j].begin(), at[j].end(), st.top());
            if (itr == at[j].begin()) {
                min_i = -1;
                break;
            }
            itr--;
            min_i = min(min_i, *itr);
        }
    }

    idx = -1;
    while (!st.empty()) {
        for (int j = 0; j < A2Z; j++) {
            auto itr = upper_bound(at[j].begin(), at[j].end(), idx);
            if (*itr >= st.top()) {
                ans.push_back('a' + j);
                idx = *itr;
                break;
            }
        }
        st.pop();
    }

    cout << ans << endl;

    return 0;

}



