//poj3249.cpp
//PKU JudgeOnline
//poj3249 Test for Job

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <stack>
#define NMAX 100000
#define INF ((long long)1 << 60)
using namespace std;


void tplsort(int a);

int N = 0;
int M = 0;
int city[NMAX];
vector<int> road[NMAX];
stack<int> tpl;
bool visited[NMAX];
long long d[NMAX];
long long ans = 0;

int main(int argc, char* argv[]){
	
	string ifn;
	string ofn;
	FILE* ifp = NULL;
	FILE* ofp = NULL;
	bool isFile = true;
	stack<int> s;
	int idx[NMAX];
	int x = 0;
	int y = 0;
	int i = 0;
	int j = 0;
	
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
	
	while(true){
		for(i = 0; i < N; i++){
			road[i].clear();
		}
		if(ifp != NULL){
			fscanf(ifp, "%d %d", &N, &M);
			for(i = 0; i < N; i++){
				fscanf(ifp, "%d", &city[i]);
			}
			for(i = 0; i < M; i++){
				fscanf(ifp, "%d %d", &x, &y);
				x--;
				y--;
				road[x].push_back(y);
			}
		}else{
			scanf("%d %d", &N, &M);
			for(i = 0; i < N; i++){
				scanf("%d", &city[i]);
			}
			for(i = 0; i < M; i++){
				scanf("%d %d", &x, &y);
				x--;
				y--;
				road[x].push_back(y);
			}
		}
		if(N == 0){
			break;
		}
		
		for(i = 0; i < N; i++){
			idx[i] = 0;
			visited[i] = false;
			d[i] = -INF;
		}
		
		for(i = 0; i < N; i++){
			x = i;
			while(true){
				if(!visited[x] && idx[x] < (int)road[x].size()){
					s.push(x);
					y = road[x][idx[x]];
					idx[x]++;
					x = y;
				}else{
					if(!visited[x]){
						tpl.push(x);
						visited[x] = true;
					}
					if(s.empty()){
						break;
					}
					x = s.top();
					s.pop();
				}
			}
		}
		
		/*for(i = 0; i < N; i++){
			tplsort(i);
		}*/
		
		ans = -INF;
		for(i = 0; i < N; i++){
			x = tpl.top();
			tpl.pop();
			
			if(d[x] == -INF){
				d[x] = city[x];
			}
			for(j = 0; j < (int)road[x].size(); j++){
				y = road[x][j];
				d[y] = max(d[y], d[x] + city[y]);
			}
			if((int)road[x].size() == 0){
				ans = max(ans, d[x]);
			}
		}
		
		if(ofp != NULL){
			fprintf(ofp, "%lld\n", ans);
		}
		printf("%lld\n", ans);
	}
	
	if(ifp != NULL){
		fclose(ifp);
	}
	if(ofp != NULL){
		fclose(ofp);
	}
	
	return 0;
	
}

void tplsort(int a){
	int i = 0;
	
	if(visited[a]){
		return;
	}
	visited[a] = true;
	
	for(i = 0; i < (int)road[a].size(); i++){
		tplsort(road[a][i]);
	}
	tpl.push(a);
	return;
}

