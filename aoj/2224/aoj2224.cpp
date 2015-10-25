//aoj2224.cpp
//AIZU ONLINE JUDGE
//aoj2224 Save your cat

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#define NMAX 10000
#define EPS 1e-10
using namespace std;


struct edge{
	int a, b;
	double cost;
};

class UnionFind{
	public:
		void init(int n);
		void unite(int a, int b);
		bool same(int a, int b);
	private:
		int root(int a);
		int par[NMAX];
		int rank[NMAX];
};

void UnionFind::init(int n){
	int i;
	
	for(i = 0; i < n; i++){
		par[i] = i;
		rank[i] = 0;
	}
	return;
}

void UnionFind::unite(int a, int b){
	a = root(a);
	b = root(b);
	if(a == b){
		return;
	}
	if(rank[a] < rank[b]){
		par[a] = b;
	}else{
		par[b] = a;
		if(rank[a] == rank[b]){
			rank[a]++;
		}
	}
	return;
}

bool UnionFind::same(int a, int b){
	return root(a) == root(b);
}

int UnionFind::root(int a){
	if(par[a] != a){
		par[a] = root(par[a]);
	}
	return par[a];
}

bool operator<(edge e1, edge e2){
	return e1.cost > e2.cost;
}

int N;	// 頂点数
int M;	// 辺数
int x[NMAX], y[NMAX];
vector<edge> e;
UnionFind uf;
double ans;

int main(){
	
	int p, q;
	double tmp_cost, tmp_sum;
	int i;
	
	scanf("%d %d", &N, &M);
	for(i = 0; i < N; i++){
		scanf("%d %d", &x[i], &y[i]);
	}
	ans = 0;
	for(i = 0; i < M; i++){
		scanf("%d %d", &p, &q);
		p--;
		q--;
		tmp_cost = sqrt((x[p] - x[q]) * (x[p] - x[q]) + (y[p] - y[q]) * (y[p] - y[q]));
		ans += tmp_cost;
		e.push_back((edge){p, q, tmp_cost});
	}
	
	sort(e.begin(), e.end());
	uf.init(N);
	tmp_sum = 0;
	for(i = 0; i < M; i++){
		if(!uf.same(e[i].a, e[i].b)){
			uf.unite(e[i].a, e[i].b);
			tmp_sum += e[i].cost;
		}
	}
	
	if(abs(ans - tmp_sum) < EPS * (ans + tmp_sum)){
		ans = 0;
	}else{
		ans -= tmp_sum;
	}
	printf("%.4f\n", ans);
	
	return 0;
	
}

