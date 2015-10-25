//poj1703.cpp
//PKU JudgeOnline
//poj1703 Find them, Catch them

#include <cstdio>
#include <cstdlib>
#include <string>
#define NMAX 100000
using namespace std;


class UnionFind{
public:
private:
	int par[NMAX * 2];
	int rank[NMAX * 2];
	int n;
public:
	void init(int num);
	int parent(int a);
	void unite(int a, int b);
	bool same(int a, int b);
private:
};

void UnionFind::init(int num){
	int i = 0;
	
	n = num;
	for(i = 0; i < n; i++){
		par[i] = i;
		rank[i] = 0;
	}
	return;
}

int UnionFind::parent(int a){
	if(par[a] != a){
		par[a] = parent(par[a]);
	}
	return par[a];
}

void UnionFind::unite(int a, int b){
	a = parent(a);
	b = parent(b);
	
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
	return parent(a) == parent(b);
}


int T = 0;
int N = 0;
int M = 0;
UnionFind uf;

int main(int argc, char* argv[]){
	
	string ifn;
	string ofn;
	FILE* ifp = NULL;
	FILE* ofp = NULL;
	bool isFile = true;
	int a = 0;
	int b = 0;
	char c;
	int t = 0;
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
		fscanf(ifp, "%d", &T);
	}else{
		scanf("%d", &T);
	}
	
	for(t = 0; t < T; t++){
		if(ifp != NULL){
			fscanf(ifp, "%d %d", &N, &M);
		}else{
			scanf("%d %d", &N, &M);
		}
		
		uf.init(N * 2);
		
		for(i = 0; i < M; i++){
			if(ifp != NULL){
				fscanf(ifp, "\n%c %d %d", &c, &a, &b);
			}else{
				scanf("\n%c %d %d", &c, &a, &b);
			}
			a--;
			b--;
			
			if(c == 'D'){
				uf.unite(a, b + N);
				uf.unite(a + N, b);
			}else if(c == 'A'){
				if(uf.same(a, b)){
					printf("In the same gang.\n");
				}else if(uf.same(a, b + N)){
					printf("In different gangs.\n");
				}else{
					printf("Not sure yet.\n");
				}
			}
		}
	}
	
	if(ifp != NULL){
		fclose(ifp);
	}
	if(ofp != NULL){
		fclose(ofp);
	}
	
	return 0;
	
}

