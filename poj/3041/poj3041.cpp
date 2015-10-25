//poj3041.cpp
//PKU JudgeOnline
//poj3041 Asteroids

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define NMAX 500
#define VMAX 2 * NMAX + 2
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
int K;
Graph graph;	// 0～N-1：縦方向、N～2N-1：横方向
int s, t;		// 2N：s、2N+1：t

int main(){
	
	int tmpx, tmpy;
	int i;
	
	scanf("%d %d", &N, &K);
	s = 2 * N;
	t = 2 * N + 1;
	for(i = 0; i < N; i++){
		graph.add_edge(s, i, 1);
		graph.add_edge(i + N, t, 1);
	}
	for(i = 0; i < K; i++){
		scanf("%d %d", &tmpx, &tmpy);
		graph.add_edge(tmpx - 1, tmpy - 1 + N, 1);
	}
	
	printf("%d\n", graph.max_flow(s, t));
	
	return 0;
	
}

