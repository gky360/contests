// AtCoder Regular Contest 065
// D - 連結 / Connectivity

#include <cstdio>
#include <map>
using namespace std;
typedef long long int ll;
typedef pair<int, int> PII;


const int MAX_N = 200000;


class UnionFind{
    public:
        void init(int n);
        void unite(int a, int b);
        bool same(int a, int b);
        int root(int a);
    private:
        int par[MAX_N];
        int rank[MAX_N];
};

void UnionFind::init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        rank[i] = 0;
    }
    return;
}

void UnionFind::unite(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) {
        return;
    }
    if (rank[a] < rank[b]) {
        par[a] = b;
    } else {
        par[b] = a;
        if (rank[a] == rank[b]) {
            rank[a]++;
        }
    }
    return;
}

bool UnionFind::same(int a, int b) {
    return root(a) == root(b);
}

int UnionFind::root(int a) {
    if (par[a] != a) {
        par[a] = root(par[a]);
    }
    return par[a];
}


int N, KL[2];
UnionFind uf[2];
map<PII, int> mp;

int main() {

    PII p;
    int a, b;

    scanf("%d%d%d", &N, &KL[0], &KL[1]);
    for (int j = 0; j < 2; j++) {
        uf[j].init(N);
        for (int i = 0; i < KL[j]; i++) {
            scanf("%d%d", &a, &b);
            uf[j].unite(a - 1, b - 1);
        }
    }

    for (int i = 0; i < N; i++) {
        p = PII(uf[0].root(i), uf[1].root(i));
        mp[p] = mp[p] + 1;
    }

    for (int i = 0; i < N; i++) {
        p = PII(uf[0].root(i), uf[1].root(i));
        printf("%d%c", mp[p], i == N - 1 ? '\n' : ' ');
    }

    return 0;

}



