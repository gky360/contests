//aoj2249.cpp
//AIZU ONLINE JUDGE
//aoj2249 Road Construction

#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#define NMAX 10000
#define MMAX 20000
#define INF 1 << 28
using namespace std;


typedef pair<int, int> P;

struct edge{
	int to, length, cost;
};

class Graph{
	public:
		void init(int n);
		void add_edge(int u, int v, int d, int c);
		int solve(int n);
	private:
		vector<edge> g[NMAX];
		int dist[NMAX];
};

void Graph::init(int n){
	int i;
	
	for(i = 0; i < n; i++){
		g[i].clear();
	}
	return;
}

void Graph::add_edge(int u, int v, int d, int c){
	g[u].push_back((edge){v, d, c});
	g[v].push_back((edge){u, d, c});
	return;
}

int Graph::solve(int n){
	priority_queue<P, vector<P>, greater<P> > q;
	int sum;
	int tmp_cost;
	P p;
	int v;
	int i;
	
	fill(dist, dist + n, INF);
	dist[0] = 0;
	q.push(P(0, 0));
	while(!q.empty()){
		p = q.top();
		q.pop();
		v = p.second;
		if(dist[v] < p.first){
			continue;
		}
		for(i = 0; i < (int)g[v].size(); i++){
			if(dist[g[v][i].to] > dist[v] + g[v][i].length){
				dist[g[v][i].to] = dist[v] + g[v][i].length;
				q.push(P(dist[g[v][i].to], g[v][i].to));
			}
		}
	}
	
	sum = 0;
	for(v = 1; v < n; v++){
		tmp_cost = INF;
		for(i = 0; i < (int)g[v].size(); i++){
			if(dist[g[v][i].to] + g[v][i].length == dist[v]){
				tmp_cost = min(tmp_cost, g[v][i].cost);
			}
		}
		sum += tmp_cost;
	}
	
	return sum;
}

int N;
int M;
Graph graph;
int ans;

int main(){
	
	int u, v, d, c;
	int i;
	
	while(true){
		scanf("%d %d", &N, &M);
		if(N == 0){
			break;
		}
		graph.init(N);
		for(i = 0; i < M; i++){
			scanf("%d %d %d %d", &u, &v, &d, &c);
			graph.add_edge(u - 1, v - 1, d, c);
		}
		ans = graph.solve(N);
		printf("%d\n", ans);
	}
	
	return 0;
	
}

