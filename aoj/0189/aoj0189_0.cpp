//aoj0189.cpp
//AIZU ONLINE JUDGE
//aoj0189 Convenient Location

#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#define VMAX 10
#define INF 1 << 28
using namespace std;


typedef pair<int, int> P;	// first:仮の最短距離, second:頂点idx

struct edge{
	int to, cost;
};

class Graph{
	public:
		void add_edge(int a, int b, int c);
		void dijkstra(int s);
		vector<edge> g[VMAX];
		int dist[VMAX];
};

void Graph::add_edge(int a, int b, int c){
	g[a].push_back((edge){b, c});
	g[b].push_back((edge){a, c});
	return;
}

void Graph::dijkstra(int s){
	priority_queue<P, vector<P>, greater<P> > q;
	P p;
	int v;
	int i;
	
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
			if(dist[g[v][i].to] > dist[v] + g[v][i].cost){
				dist[g[v][i].to] = dist[v] + g[v][i].cost;
				q.push(P(dist[g[v][i].to], g[v][i].to));
			}
		}
	}
	return;
}

int N;
int V;	// 町の数
int ans_town, ans_sum;

int main(){
	
	int sum;
	int a, b, c;
	int i, j;
	
	while(true){
		Graph graph;
		
		scanf("%d", &N);
		if(N == 0){
			break;
		}
		V = 0;
		for(i = 0; i < N; i++){
			scanf("%d %d %d", &a, &b, &c);
			graph.add_edge(a, b, c);
			V = max(V, max(a, b));
		}
		V++;
		
		ans_sum = INF;
		for(i = 0; i < V; i++){
			graph.dijkstra(i);
			sum = 0;
			for(j = 0; j < V; j++){
				sum += graph.dist[j];
			}
			if(ans_sum > sum){
				ans_town = i;
				ans_sum = sum;
			}
		}
		
		printf("%d %d\n", ans_town, ans_sum);
	}
	
	return 0;
	
}

