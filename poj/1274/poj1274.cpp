//poj1274.cpp
//PKU Judge Online
//poj1274 The Perfect Stall

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define NMAX 200
#define MMAX 200
#define VMAX NMAX + MMAX + 2
#define INF 100000000
using namespace std;

struct edge{
	int to, cap, rev;
};

class Graph{
	private:
		vector<edge> g[VMAX];
		int level[VMAX];
		int iter[VMAX];
		void bfs(int s);
		int dfs(int v, int t, int f);
	public:
		void add_edge(int a, int b, int cap);
		void clear();
		int max_flow(int s, int t);
};

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

void Graph::bfs(int s){
	int v;
	queue<int> q;
	int i;
	
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
	int i;
	
	if(v == t){
		return f;
	}
	for(i = 0; i < (int)g[v].size(); i++){
		edge &e = g[v][i];
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


int N, M;
Graph graph;	// 0~N-1:cow, N^N+M-1:stall, N+M:S, N+M+1:T
int ans;

int main(){
	
	int si;
	int tmp;
	int i, j;
	
	while(scanf("%d %d", &N, &M) != EOF){
		for(i = 0; i < N; i++){
			graph.add_edge(N + M, i, 1);
		}
		for(i = 0; i < M; i++){
			graph.add_edge(N + i, N + M + 1, 1);
		}
		for(i = 0; i < N; i++){
			scanf("%d", &si);
			for(j = 0; j < si; j++){
				scanf("%d", &tmp);
				graph.add_edge(i, N + tmp - 1, 1);
			}
		}
		
		ans = graph.max_flow(N + M, N + M + 1);
		printf("%d\n", ans);
		
		graph.clear();
	}
	
	return 0;
	
}

