//aoj2230.cpp
//AIZU ONLINE JUDGE
//aoj2230 How to Create a Good Game

#include <cstdio>
#include <vector>
#define NMAX 100
#define VMAX NMAX + 1
#define INF 100000
using namespace std;


int N;
int M;

struct edge{
	int to, cap, cost, rev;
};

class Graph{
	public:
		void add_limited_edge(int from, int to, int cap, int min_cap, int cost);
		void add_edge(int from, int to, int cap, int cost);
		void bmfd(int s, int di);	// ベルマンフォード法
		int min_cost_flow(int s, int t);
		vector<edge> g[VMAX];
		int dist[VMAX];
		int pre_v[VMAX], pre_e[VMAX];
};

void Graph::add_limited_edge(int from, int to, int cap, int min_cap, int cost){
	add_edge(from, to, cap - min_cap, cost);
	add_edge(from, to, min_cap, cost - INF);
	return;
}

void Graph::add_edge(int from, int to, int cap, int cost){
	g[from].push_back((edge){to, cap, cost, g[to].size()});
	g[to].push_back((edge){from, 0, -cost, g[from].size() - 1});
	return;
}

void Graph::bmfd(int s, int di){
	bool update = true;
	int v, i;
	
	fill(dist, dist + N + 1, INF);
	dist[s] = 0;
	while(update){
		update = false;
		for(v = 0; v < N + 1; v++){
			if(dist[v] >= INF){
				continue;
			}
			for(i = 0; i < (int)g[v].size(); i += di){
				if(g[v][i].cap > 0 && dist[g[v][i].to] > dist[v] + g[v][i].cost){
					dist[g[v][i].to] = dist[v] + g[v][i].cost;
					pre_v[g[v][i].to] = v;
					pre_e[g[v][i].to] = i;
					update = true;
				}
			}
		}
	}
	return;
}

int Graph::min_cost_flow(int s, int t){
	int sum = 0;
	int v;
	
	while(true){
		bmfd(s, 1);
		
		if(dist[t] >= 0){
			break;
		}
		
		// dは常に1なので計算は省略
		sum += dist[t];
		for(v = t; v != s; v = pre_v[v]){
			edge &e = g[pre_v[v]][pre_e[v]];
			e.cap--;
			g[v][e.rev].cap++;
		}
	}
	
	return sum + INF * M;
}


Graph graph;
int ans;

int main(){
	
	int from, to, cost;
	int i;
	
	scanf("%d %d", &N, &M);
	for(i = 0; i < M; i++){
		scanf("%d %d %d", &from, &to, &cost);
		graph.add_limited_edge(from, to, INF, 1, -cost);
	}
	graph.bmfd(0, 2);
	graph.add_edge(N - 1, N, INF, (int)(-graph.dist[N - 1] % INF));
	
	ans = graph.min_cost_flow(0, N);
	
	printf("%d\n", ans);
	
	return 0;
	
}

