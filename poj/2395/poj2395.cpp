//poj2395.cpp
//PKU JudgeOnline
//poj2395 Out of Hay

#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#define NMAX 2000
#define MMAX 10000
using namespace std;


class UnionFind{
public:
	int par[NMAX];
	int rank[NMAX];
private:
public:
	void init(int n);
	int root(int a);
	void unite(int a, int b);
	bool same(int a, int b);
private:
};

void UnionFind::init(int n){
	int i = 0;
	
	for(i = 0; i < n; i++){
		par[i] = i;
		rank[i] = 0;
	}
	return;
}

int UnionFind::root(int a){
	if(par[a] != a){
		par[a] = root(par[a]);
	}
	return par[a];
}

void UnionFind::unite(int a, int b){
	a = root(a);
	b = root(b);
	if(rank[a] > rank[b]){
		par[b] = a;
	}else if(rank[a] < rank[b]){
		par[a] = b;
	}else{
		par[b] = a;
		rank[a]++;
	}
	return;
}

bool UnionFind::same(int a, int b){
	return root(a) == root(b);
}

class Edge{
public:
	int from;
	int to;
	int w;
private:
public:
private:
};

bool operator <(Edge e1, Edge e2);

int N = 0;
int M = 0;
Edge road[MMAX];
UnionFind uf;
int ans = 0;

int main(int argc, char* argv[]){
	
	string ifn;
	string ofn;
	FILE* ifp = NULL;
	FILE* ofp = NULL;
	bool isFile = true;
	int num = 0;
	int i = 0;
	
	if(argc == 3){
		ifn = argv[1];
		ofn = argv[2];
	}else if(argc == 2){
		ifn = argv[1];
		ofn = "output.txt";
	}else{
		isFile = false;
	}
	
	if(isFile){
		ifp = fopen(ifn.c_str(), "r");
		if(ifp == NULL){
			printf("入力ファイル %s を開けませんでした。", ifn.c_str());
			return -1;
		}
		ofp = fopen(ofn.c_str(), "w");
		if(ofp == NULL){
			printf("出力ファイル %s を開けませんでした。", ofn.c_str());
			return -1;
		}
	}
	
	if(ifp != NULL){
		fscanf(ifp, "%d %d", &N, &M);
		for(i = 0; i < M; i++){
			fscanf(ifp, "%d %d %d", &road[i].from, &road[i].to, &road[i].w);
			road[i].from--;
			road[i].to--;
		}
	}else{
		scanf("%d %d", &N, &M);
		for(i = 0; i < M; i++){
			scanf("%d %d %d", &road[i].from, &road[i].to, &road[i].w);
			road[i].from--;
			road[i].to--;
		}
	}
	uf.init(N);
	
	sort(road, road + M);
	
	num = 0;
	for(i = 0; i < M; i++){
		if(!uf.same(road[i].from, road[i].to)){
			uf.unite(road[i].from, road[i].to);
			num++;
			if(num >= N - 1){
				ans = road[i].w;
				break;
			}
		}
	}
	
	if(ofp != NULL){
		fprintf(ofp, "%d\n", ans);
	}
	printf("%d\n", ans);
	
	if(ifp != NULL){
		fclose(ifp);
	}
	if(ofp != NULL){
		fclose(ofp);
	}
	
	return 0;
	
}

bool operator <(Edge e1, Edge e2){
	return e1.w < e2.w;
}

