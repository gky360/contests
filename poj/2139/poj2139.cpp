//poj2139.cpp
//PKU JudgeOnline
//poj2139 Six Degrees of Cowvin Bacon

#include <cstdio>
#include <vector>
#define NMAX 300
#define INF 100000000
using namespace std;


int N;
int M;
int Mi;
vector<int> movie;
int graph[NMAX][NMAX];
int ans;

int main(){
	
	int tmp;
	int i, j, k;
	
	scanf("%d %d", &N, &M);
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			graph[i][j] = INF;
		}
	}
	
	for(k = 0; k < M; k++){
		scanf("%d", &Mi);
		for(i = 0; i < Mi; i++){
			scanf("%d", &tmp);
			movie.push_back(tmp - 1);
		}
		for(i = 0; i < Mi; i++){
			for(j = i + 1; j < Mi; j++){
				graph[movie[i]][movie[j]] = 1;
				graph[movie[j]][movie[i]] = 1;
			}
		}
		movie.clear();
	}
	for(i = 0; i < N; i++){
		graph[i][i] = 0;
	}
	
	for(k = 0; k < N; k++){
		for(i = 0; i < N; i++){
			for(j = 0; j < N; j++){
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	
	ans = INF;
	for(j = 0; j < N; j++){
		tmp = 0;
		for(i = 0; i < N; i++){
			if(i == j){
				continue;
			}
			tmp += graph[i][j] * 100;
		}
		ans = min(ans, tmp / (N - 1));
	}
	
	printf("%d\n", ans);
	
	return 0;
	
}

