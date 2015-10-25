//poj2377.cpp
//PKU JudgeOnline
//poj2377 Bad Cowtractors

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#define MAX_V MAX_N
#define MAX_N 1000
#define MAX_M 20000
using namespace std;


typedef pair<int, int> PAIR;	// first: cost, second: v_index

class Graph
{
public:
	void add_edge(int from, int to, int cost);
	int prim();	// 最小全域木のコストを返す。グラフが連結でない場合は0を返す。
	int V;
private:
	vector<PAIR> g[MAX_V];
};

void Graph::add_edge(int from, int to, int cost)
{
	g[from].push_back(PAIR(cost, to));
	return;
}

int Graph::prim()
{
	priority_queue<PAIR, vector<PAIR>, greater<PAIR> > q;
	bool used[MAX_V];
	int cost;
	PAIR p;	// first: cost, second: v_index
	int v;
	int n;
	int i;

	memset(used, 0, sizeof(used));
	q.push(PAIR(0, 0));
	cost = 0;
	n = 0;
	while(!q.empty()){
		p = q.top();
		q.pop();
		v = p.second;
		if(used[v]){
			continue;
		}
		used[v] = true;
		cost += p.first;
		n++;
		for(i = 0; i < (int)g[v].size(); i++){
			if(!used[g[v][i].second]){
				q.push(g[v][i]);
			}
		}
	}
	if(n < V){
		return 0;
	}
	return cost;
}

int N;
int M;
Graph G;
int ans;

int main()
{
	int a, b;
	int cost;
	int i;

	scanf("%d %d", &N, &M);
	G.V = N;
	for(i = 0; i < M; i++){
		scanf("%d %d %d", &a, &b, &cost);
		G.add_edge(a - 1, b - 1, -cost);
		G.add_edge(b - 1, a - 1, -cost);
	}

	ans = -G.prim();
	if(ans == 0){
		ans = -1;
	}

	printf("%d\n", ans);

	return 0;
}

