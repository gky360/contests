//poj3692_2.cpp
//PKU JudgeOnline
//poj3692 Kindergarten

#include <cstdio>
#include <cstring>
#include <vector>
#define GMAX 200
#define BMAX 200
#define VMAX GMAX + BMAX
using namespace std;


int G, B;
int M;
bool table[GMAX][BMAX];
int V = 0;
vector<int> g[VMAX];	// 0~G-1:girls, G~G+B-1:boys
int match[VMAX];
bool used[VMAX];
int ans;

void init(){
	int v;
	
	for(v = 0; v < V; v++){
		g[v].clear();
	}
	return;
}

void add_edge(int u, int v){
	g[u].push_back(v);
	g[v].push_back(u);
	return;
}

bool dfs(int v){
	int u, w;
	int i;
	
	used[v] = true;
	for(i = 0; i < (int)g[v].size(); i++){
		u = g[v][i];
		w = match[u];
		if(w < 0 || (!used[w] && dfs(w))){
			match[u] = v;
			match[v] = u;
			return true;
		}
	}
	return false;
}

int bipartite_matching(){
	int res = 0;
	int v;
	
	memset(match, -1, sizeof(match));
	for(v = 0; v < V; v++){
		if(match[v] < 0){
			memset(used, false, sizeof(used));
			if(dfs(v)){
				res++;
			}
		}
	}
	return res;
}

int main(){
	
	int cnt;
	int x, y;
	int i, j;
	
	for(cnt = 1; ; cnt++){
		scanf("%d %d %d", &G, &B, &M);
		if(M == 0){
			break;
		}
		init();
		V = G + B;
		
		memset(table, false, sizeof(table));
		for(i = 0; i < M; i++){
			scanf("%d %d", &x, &y);
			table[x - 1][y - 1] = true;
		}
		
		for(i = 0; i < G; i++){
			for(j = 0; j < B; j++){
				if(!table[i][j]){
					add_edge(i, j + G);
				}
			}
		}
		
		ans = V - bipartite_matching();
		printf("Case %d: %d\n", cnt, ans);
		
	}
	
	return 0;
	
}

