//poj3469.cpp
//PKU JudgeOnline
//poj3469 Dual Core CPU

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define NMAX 20000
#define VMAX NMAX + 2
#define INF 100000000
using namespace std;


struct edge{
	int to, cap, rev;
};

class Graph{
	public:
		void add_edge(int from, int to, int cap);
		int max_flow(int s, int t);
	private:
		void bfs(int s);
		int dfs(int v, int t, int f);
	private:
		vector<edge> g[VMAX];
		int level[VMAX];
		int iter[VMAX];
};

void Graph::add_edge(int from, int to, int cap){
	g[from].push_back((edge){to, cap, g[to].size()});
	g[to].push_back((edge){from, 0, g[from].size() - 1});
	return;
}

void Graph::bfs(int s){
	queue<int> que;
	int v, i;
	
	memset(level, -1, sizeof(level));
	level[s] = 0;
	que.push(s);
	while(!que.empty()){
		v = que.front();
		que.pop();
		for(i = 0; i < g[v].size(); i++){
			if(g[v][i].cap > 0 && level[g[v][i].to] < 0){
				level[g[v][i].to] = level[v] + 1;
				que.push(g[v][i].to);
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
	for( ; iter[v] < g[v].size(); iter[v]++){
		edge &e = g[v][iter[v]];
		if(e.cap > 0 && level[v] < level[e.to]){
			d = dfs(e.to, t, min(f, e.cap));
			if(d <= 0){
				continue;
			}
			e.cap -= d;
			g[e.to][e.rev].cap += d;
			return d;
		}
	}
	return 0;
}

int Graph::max_flow(int s, int t){
	int flow = 0;
	int f;
	
	while(true){
		bfs(s);
		if(level[t] < 0){
			break;
		}
		memset(iter, 0, sizeof(iter));
		while((f = dfs(s, t, INF)) > 0){
			flow += f;
		}
	}
	return flow;
}

int N;
int M;
Graph graph;	// 0～N-1：モジュール、N：s、N+1：t
int s, t;
int ans;

int main(){
	
	int a, b, w;
	int i;
	
	scanf("%d %d", &N, &M);
	s = N;
	t = N + 1;
	for(i = 0; i < N; i++){
		scanf("%d %d", &a, &b);
		graph.add_edge(s, i, b);
		graph.add_edge(i, t, a);
	}
	for(i = 0; i < M; i++){
		scanf("%d %d %d", &a, &b, &w);
		graph.add_edge(a - 1, b - 1, w);
		graph.add_edge(b - 1, a - 1, w);
	}
	
	ans = graph.max_flow(s, t);
	printf("%d\n", ans);
	
	return 0;
	
}

