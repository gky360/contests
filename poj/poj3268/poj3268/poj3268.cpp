//poj3268.cpp
//PKU JudgeOnline
//poj3268 Silver Cow Party

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#define MAX_V MAX_N
#define INF 100000000
#define MAX_N 1000
using namespace std;


typedef pair<int, int> PAIR;	// first:cost, second:v_index


class Graph
{
public:
	void add_edge(int from, int to, int cost);
	void dijkstra(int s);
	int d[MAX_V];
	int V;
private:
	vector<PAIR> g[MAX_V];
};

void Graph::add_edge(int from, int to, int cost)
{
	g[from].push_back(PAIR(cost, to));
	return;
}

void Graph::dijkstra(int s)
{
	priority_queue<PAIR, vector<PAIR>, greater<PAIR> > q;
	PAIR p;	// first:cost, second:v_index
	PAIR e;	// first:cost, second:v_index
	int i;

	fill(d, d + V, INF);
	d[s] = 0;
	q.push(PAIR(d[s], s));
	while(!q.empty()){
		p = q.top();
		q.pop();
		if(d[p.second] < p.first){
			continue;
		}
		for(i = 0; i < (int)g[p.second].size(); i++){
			e = g[p.second][i];
			if(d[e.second] > d[p.second] + e.first){
				d[e.second] = d[p.second] + e.first;
				q.push(PAIR(d[e.second], e.second));
			}
		}
	}
	return;
}


int N;
int M;
int X;
Graph G;
int dist[MAX_N];
int ans;

int main()
{
	int a, b, t;
	int i;

	scanf("%d %d %d", &N, &M, &X);
	X--;
	G.V = N;
	for(i = 0; i < M; i++){
		scanf("%d %d %d", &a, &b, &t);
		G.add_edge(a - 1, b - 1, t);
	}

	for(i = 0; i < N; i++){
		if(i == X){
			dist[X] = 0;
			continue;
		}
		G.dijkstra(i);
		dist[i] = G.d[X];
	}
	G.dijkstra(X);
	ans = 0;
	for(i = 0; i < N; i++){
		dist[i] += G.d[i];
		ans = max(ans, dist[i]);
	}

	printf("%d\n", ans);

	return 0;
}

