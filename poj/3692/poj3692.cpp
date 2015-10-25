//poj3692.cpp
//PKU JudgeOnline
//poj3692 Kindergarten

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define GMAX 200
#define BMAX 200
#define VMAX GMAX + BMAX + 2
#define INF 100000000
using namespace std;


struct edge{
	int to, cap, rev;
};

class Graph{
	private:
		vector<edge> g[VMAX];
		int iter[VMAX];
		int level[VMAX];
		void bfs(int s);
		int dfs(int v, int t, int f);
	public:
		void clear();
		void add_edge(int a, int b, int cap);
		int max_flow(int s, int t);
};

void Graph::bfs(int s){
	queue<int> q;
	int v, i;
	
	memset(level, -1, sizeof(level));
	level[s] = 0;
	q.push(s);
	while(!q.empty()){
		v = q.front();
		q.pop();
		for(i = 0; i < (int)g[v].size(); i++){
			if(g[v][i].cap > 0 && level[g[v][i].to] < 0){
				level[g[v][i].to] = level[v] + 1;
				q.push(g[v][i].to);
			}
		}
	}
	return;
}

int Graph::dfs(int v, int t, int f){
	int d;
	
	if(v == t){
		return f;
	}
	for( ; iter[v] < (int)g[v].size(); iter[v]++){
		edge &e = g[v][iter[v]];
		if(e.cap > 0 && level[v] < level[e.to]){
			d = dfs(e.to, t, min(f, e.cap));
			if(d > 0){
				e.cap -= d;
				g[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	
	return 0;
}

void Graph::clear(){
	int i;
	
	for(i = 0; i < VMAX; i++){
		g[i].clear();
	}
	return;
}

void Graph::add_edge(int a, int b, int cap){
	g[a].push_back((edge){b, cap, g[b].size()});
	g[b].push_back((edge){a, 0, g[a].size() - 1});
	return;
}

int Graph::max_flow(int s, int t){
	int f;
	int flow = 0;
	
	while(true){
		bfs(s);
		if(level[t] < 0){
			break;
		}
		memset(iter, 0, sizeof(iter));
		do{
			f = dfs(s, t, INF);
			flow += f;
		}while(f > 0);
	}
	
	return flow;
}


int G, B;
int M;
bool table[GMAX][BMAX];
Graph graph;	// 0~G-1:girls, G~G+B-1:boys, G+B:S, G+B+1:T
int ans;

int main(){
	
	int cnt;
	int x, y;
	int i, j;
	
	for(cnt = 1; ; cnt++){
		scanf("%d %d %d", &G, &B, &M);
		if(M == 0){
			break;
		}
		
		graph.clear();
		memset(table, false, sizeof(table));
		for(i = 0; i < M; i++){
			scanf("%d %d", &x, &y);
			table[x - 1][y - 1] = true;
		}
		
		for(i = 0; i < G; i++){
			graph.add_edge(G + B, i, 1);
		}
		for(j = 0; j < B; j++){
			graph.add_edge(j + G, G + B + 1, 1);
		}
		for(i = 0; i < G; i++){
			for(j = 0; j < B; j++){
				if(!table[i][j]){
					graph.add_edge(i, j + G, 1);
				}
			}
		}
		ans = G + B - graph.max_flow(G + B, G + B + 1);
		printf("Case %d: %d\n", cnt, ans);
	}
	
	return 0;
	
}

