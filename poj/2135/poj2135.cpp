//poj2135.cpp
//PKU JudgeOnline
//poj2135 Farm Tour

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#define NMAX 1000
#define VMAX NMAX
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
	private:
		vector<edge> g[VMAX];
		int h[VMAX];
		int dist[VMAX];
		int pre_v[VMAX], pre_e[VMAX];
};

void Graph::add_edge(int from, int to, int cap, int cost){
	g[from].push_back((edge){to, cap, cost, g[to].size()});
	g[to].push_back((edge){from, 0, -cost, g[from].size() - 1});
	return;
}

int Graph::min_cost_flow(int s, int t, int f){
	priority_queue<P, vector<P>, greater<P> > que;
			// first:仮の最短距離, second:頂点番号
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
				edge /*&*/e = g[v][i];
				if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
					dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
					pre_v[e.to] = v;
					pre_e[e.to] = i;
					que.push(P(dist[e.to], e.to));
				}
			}
		}
		if(dist[t] >= INF){
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
Graph graph;	// 0:家, N - 1:納屋
int ans;

int main(){
	
	int from, to, length;
	int i;
	
	scanf("%d %d", &N, &M);
	for(i = 0; i < M; i++){
		scanf("%d %d %d", &from, &to, &length);
		graph.add_edge(from - 1, to - 1, 1, length);
		graph.add_edge(to - 1, from - 1, 1, length);
	}
	
	ans = graph.min_cost_flow(0, N - 1, 2);
	printf("%d\n", ans);
	
	return 0;
	
}

