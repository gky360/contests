//poj2914.cpp
//PKU JudgeOnline
//poj2914 Minimum Cut

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define MAX_V MAX_N
#define MAX_N 500
#define INF 10000000000000000
using namespace std;
typedef long long LL;


class Edge
{
public:
	int to, cap, rev, orig;
	Edge(int to_p, int cap_p, int rev_p);
};

Edge::Edge(int to_p, int cap_p, int rev_p)
{
	to = to_p;
	cap = orig = cap_p;
	rev = rev_p;
	return;
}

class Graph
{
public:
	void add_edge(int from, int to, int cap);
	LL max_flow(int s, int t);
	void init();
private:
	void bfs(int s);
	int dfs(int v, int t, int f);
	vector<Edge> g[MAX_V];
	int level[MAX_V];
	int iter[MAX_V];
};

void Graph::add_edge(int from, int to, int cap)
{
	g[from].push_back(Edge(to, cap, g[to].size()));
	g[to].push_back(Edge(from, 0, g[from].size() - 1));
	return;
}

LL Graph::max_flow(int s, int t)
{
	int f;
	LL flow = 0;

	int v, i;
	for (v = 0; v < MAX_V; v++) {
		for (i = 0; i < g[v].size(); i++) {
			g[v][i].cap = g[v][i].orig;
		}
	}

	while (true) {
		bfs(s);
		if (level[t] < 0) {
			break;
		}
		memset(iter, 0, sizeof(iter));
		while (f = dfs(s, t, INF) > 0) {
			flow += f;
		}
	}

	return flow;
}

void Graph::init()
{
	int v;

	for (v = 0; v < MAX_V; v++) {
		g[v].clear();
	}
	return;
}

void Graph::bfs(int s)
{
	queue<int> q; 
	int v;
	int i;

	memset(level, -1, sizeof(level));
	level[s] = 0;
	q.push(s);
	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (i = 0; i < g[v].size(); i++) {
			if (g[v][i].cap > 0 && level[g[v][i].to] < 0) {
				level[g[v][i].to] = level[v] + 1;
				q.push(g[v][i].to);
			}
		}
	}
	return;
}

int Graph::dfs(int v, int t, int f)
{
	int d;

	if (v == t) {
		return f;
	}

	for (; iter[v] < g[v].size(); iter[v]++) {
		Edge &e = g[v][iter[v]];
		if (e.cap > 0 && level[e.to] > level[v]) {
			d = dfs(e.to, t, min(f, e.cap));
			if (d > 0) {
				e.cap -= d;
				g[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}


int N;
int M;
Graph g;
LL ans;

int main()
{
	int a, b, c;
	int i, j;

	while (scanf("%d %d", &N, &M) == 2) {
		g.init();
		for (i = 0; i < M; i++) {
			scanf("%d %d %d", &a, &b, &c);
			g.add_edge(a, b, c);
			g.add_edge(b, a, c);
		}

		ans = INF;
		for (i = 0; i < N; i++) {
			for (j = i + 1; j < N; j++) {
				ans = min(ans, g.max_flow(i, j));
			}
		}

		printf("%lld\n", ans);
	}

	return 0;
}
