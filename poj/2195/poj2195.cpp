//poj2195.cpp
//PKU JudegOnline
//poj2195 GoingHome

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#define HMAX 100
#define VMAX HMAX * 2 + 2
#define INF 100000000
using namespace std;


typedef pair<int, int> P;

struct edge{
	int to, cap, cost, rev;
};

class Graph{
	public:
		vector<edge> g[VMAX];
		int h[VMAX];
		int dist[VMAX];
		int pre_v[VMAX], pre_e[VMAX];
		void add_edge(int from, int to, int cap, int cost);
		int min_cost_flow(int s, int t, int f);
};

void Graph::add_edge(int from, int to, int cap, int cost){
	g[from].push_back((edge){to, cap, cost, g[to].size()});
	g[to].push_back((edge){from, 0, -cost, g[from].size() - 1});
	return;
}

int Graph::min_cost_flow(int s, int t, int f){
	priority_queue<P, vector<P>, greater<P> > q;	// first:‰¼‚ÌÅ’Z‹——£, second:’¸“_”Ô†
	P p;
	int v;
	int sum = 0;
	int i;
	
	fill(h, h + VMAX, 0);
	while(f > 0){
		fill(dist, dist + VMAX, INF);
		dist[s] = 0;
		q.push(P(0, s));
		while(!q.empty()){
			p = q.top();
			q.pop();
			v = p.second;
			if(dist[v] < p.first){
				continue;
			}
			for(i = 0; i < (int)g[v].size(); i++){
				if(g[v][i].cap > 0 && dist[g[v][i].to] > dist[v] + g[v][i].cost + h[v] - h[g[v][i].to]){
					dist[g[v][i].to] = dist[v] + g[v][i].cost + h[v] - h[g[v][i].to];
					pre_v[g[v][i].to] = v;
					pre_e[g[v][i].to] = i;
					q.push(P(dist[g[v][i].to], g[v][i].to));
				}
			}
		}
		if(dist[t] >= INF){
			return -1;
		}
		
		for(v = 0; v < VMAX; v++){
			h[v] = min(h[v] + dist[v], INF);
		}
		
		f--;
		sum += h[t] * 1;
		for(v = t; v != s; v = pre_v[v]){
			edge &e = g[pre_v[v]][pre_e[v]];
			e.cap--;
			g[v][e.rev].cap++;
		}
	}
	return sum;
}


int N, M;
int H;
P m[HMAX], h[HMAX];	// l‚Æ‰Æ‚ÌÀ•W
int ans;

int main(){
	
	char c;
	int d;
	int i, j, k, l;
	
	while(true){
		Graph graph;	// 0~H-1:m, H~2H-1:h, 2H:s, 2H+1:t
		
		scanf("%d %d", &N, &M);
		if(N == 0){
			break;
		}
		k = 0;
		l = 0;
		for(i = 0; i < N; i++){
			scanf("%c", &c);
			for(j = 0; j < M; j++){
				scanf("%c", &c);
				if(c == 'm'){
					m[k].first = i;
					m[k].second = j;
					k++;
				}else if(c == 'H'){
					h[l].first = i;
					h[l].second = j;
					l++;
				}
			}
		}
		H = k;
		
		for(i = 0; i < H; i++){
			graph.add_edge(2 * H, i, 1, 0);
			graph.add_edge(H + i, 2 * H + 1, 1, 0);
		}
		for(i = 0; i < H; i++){
			for(j = 0; j < H; j++){
				d = abs(m[i].first - h[j].first) + abs(m[i].second - h[j].second);
				graph.add_edge(i, H + j, 1, d);
			}
		}
		ans = graph.min_cost_flow(2 * H, 2 * H + 1, H);
		
		printf("%d\n", ans);
	}
	
	return 0;
	
}

