//dijkstra.cpp
//�_�C�N�X�g���@(�L���O���t�p)
//�O���t�͗אڃ��X�g�^

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#define MAX_V 1000
#define INF 100000000
using namespace std;


typedef pair<int, int> PAIR;	// first:cost, second:v_index


class Graph
{
public:
	void add_edge(int from, int to, int cost);
	void dijkstra(int s);
	int dist[MAX_V];
	int V;	// ���������Y�ꂸ��
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

	fill(dist, dist + V, INF);
	dist[s] = 0;
	q.push(PAIR(dist[s], s));
	while(!q.empty()){
		p = q.top();
		q.pop();
		if(dist[p.second] < p.first){
			continue;
		}
		for(i = 0; i < (int)g[p.second].size(); i++){
			e = g[p.second][i];
			if(dist[e.second] > dist[p.second] + e.first){
				dist[e.second] = dist[p.second] + e.first;
				q.push(PAIR(dist[e.second], e.second));
			}
		}
	}
	return;
}


int main()
{
	return 0;
}

