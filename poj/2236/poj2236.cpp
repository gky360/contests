//poj2236.cpp
//PKU JudgeOnline
//poj2236 WirelessNetwork

#include <cstdio>
#include <cstring>
#define NMAX 1001
using namespace std;


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

int UnionFind::root(int a){
	if(par[a] != a){
		par[a] = root(par[a]);
	}
	return par[a];
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

int N;
int D;
int loc[NMAX][2];	// location
bool repared[NMAX];
UnionFind uf;

int main(){
	
	int a, b;
	int x, y;
	char os;
	int i;
	
	scanf("%d %d", &N, &D);
	uf.init(N);
	memset(repared, 0, N);
	for(i = 0; i < N; i++){
		scanf("%d %d", &loc[i][0], &loc[i][1]);
	}
	while(true){
		scanf("%c", &os);
		if(scanf("%c", &os) == EOF){
			break;
		}
		
		if(os == 'O'){
			scanf("%d", &a);
			a--;
			for(i = 0; i < N; i++){
				x = loc[a][0] - loc[i][0];
				y = loc[a][1] - loc[i][1];
				if(repared[i] && (x * x + y * y <= D * D)){
					uf.unite(a, i);
				}
			}
			repared[a] = true;
		}else{
			scanf("%d %d", &a, &b);
			a--;
			b--;
			if(uf.same(a, b)){
				printf("SUCCESS\n");
			}else{
				printf("FAIL\n");
			}
		}
	}
	
	return 0;
}

