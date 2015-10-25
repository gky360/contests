//poj2175.cpp
//PKU JudgeOnline
//poj2175 Evacuation Plan

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#define NMAX 100
#define MMAX 100
#define VMAX NMAX + MMAX + 2
#define INF 100000000
using namespace std;


typedef pair<int, int> P;

struct edge{
	int to, cap, cost, rev;
};

class Graph{
	public:
		void add_edge(int from, int to, int cap, int cost);
		int min_cost_flow(int s, int t, int f);
	//private:
		vector<edge> g[VMAX];
		int h[VMAX];
		int dist[VMAX];
		int pre_v[VMAX], pre_e[VMAX];
};

void Graph::add_edge(int from, int to, int cap, int cost){
	g[from].push_back((edge){to, cap, cost, g[to].size()});
	g[to].push_back((edge){from, 0, -cost, g[from].size() - 1});
}

int Graph::min_cost_flow(int s, int t, int f){
	priority_queue<P, vector<P>, greater<P> > que;
			// first:最短距離, second:頂点番号
	P p;
	int v;
	int d;
	int cost = 0;
	int i;
	
	memset(h, 0, sizeof(h));
	while(f > 0){
		fill(dist, dist + VMAX, INF);
		dist[s] = 0;
		que.push(P(0, s));
		while(!que.empty()){
			p = que.top();
			que.pop();
			v = p.second;
			if(dist[v] < p.first){
				continue;
			}
			for(i = 0; i < (int)g[v].size(); i++){
				edge &e = g[v][i];
				if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
					dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
					pre_v[e.to] = v;
					pre_e[e.to] = i;
					que.push(P(dist[e.to], e.to));
				}
			}
		}
		if(dist[t] == INF){
			return -1;
		}
		
		for(v = 0; v < VMAX; v++){
			h[v] = min(INF, h[v] + dist[v]);
		}
		
		d = f;
		for(v = t; v != s; v = pre_v[v]){
			d = min(d, g[pre_v[v]][pre_e[v]].cap);
		}
		f -= d;
		cost += h[t] * d;
		for(v = t; v != s; v = pre_v[v]){
			edge &e = g[pre_v[v]][pre_e[v]];
			e.cap -= d;
			g[v][e.rev].cap += d;
		}
	}
	return cost;
}

int N;
int M;
int buil[NMAX][3];
int shel[MMAX][3];
Graph graph;	// 0～N-1:ビル, N～N+M-1:シェルター, N+M:s, N+M+1:t
int people = 0;
int time = 0;

int main(){
	
	int tmp;
	int i, j;
	
	scanf("%d %d", &N, &M);
	people = 0;
	for(i = 0; i < N; i++){
		scanf("%d %d %d", &buil[i][0], &buil[i][1], &buil[i][2]);
		graph.add_edge(N + M, i, buil[i][2], 0);
		people += buil[i][2];
	}
	for(j = 0; j < M; j++){
		scanf("%d %d %d", &shel[j][0], &shel[j][1], &shel[j][2]);
		graph.add_edge(j + N, N + M + 1, shel[j][2], 0);
	}
	time = 0;
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			scanf("%d", &tmp);
			graph.add_edge(i, j + N, INF, abs(buil[i][0] - shel[j][0]) + abs(buil[i][1] - shel[j][1]) + 1);
			time += tmp * (abs(buil[i][0] - shel[j][0]) + abs(buil[i][1] - shel[j][1]) + 1);
		}
	}
	
	if(time > graph.min_cost_flow(N + M, N + M + 1, people)){
		printf("SUBOPTIMAL\n");
		for(i = 0; i < N; i++){
			for(j = 0; j < M; j++){
				printf("%d%c", graph.g[j + N][i + 1].cap, j == M - 1 ? '\n' : ' ');
			}
		}
	}else{
		printf("OPTIMAL\n");
	}
	
	return 0;
	
}

