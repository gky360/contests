//poj3126.cpp
//PKU JudgeOnline
//poj3126 Prime Path

#include <cstdio>
#include <vector>
#include <queue>
#define INF 100000000
using namespace std;


int A, B;
int N;
bool prime[10000];
vector<int> g[9000];	// g[i-A]はiの頂点
int level [9000];	// level[i-A]はiのレベル
queue<int> q;

int main(){
	
	int a, b;
	int cnt;
	int v;
	int i, j, k;
	
	fill(prime, prime + 10000, true);
	for(i = 2; i * i < 10000; i++){
		if(prime[i]){
			for(j = i * 2; j < 10000; j += i){
				prime[j] = false;
			}
		}
	}
	
	for(i = 1000; i < 10000; i++){
		if(!prime[i]){
			continue;
		}
		for(j = i + 1; j < 10000; j++){
			if(!prime[j]){
				continue;
			}
			a = i;
			b = j;
			cnt = 0;
			while(a > 0){
				if(a % 10 == b % 10){
					cnt++;
				}
				a /= 10;
				b /= 10;
			}
			if(cnt == 3){
				g[i - 1000].push_back(j);
				g[j - 1000].push_back(i);
			}
		}
	}
	
	scanf("%d", &N);
	for(k = 0; k < N; k++){
		scanf("%d %d", &A, &B);
		if(A > B){
			swap(A, B);
		}
		
		fill(level, level + 9000, INF);
		level[A - 1000] = 0;
		q.push(A);
		while(!q.empty()){
			v = q.front();
			q.pop();
			for(i = 0; i < (int)g[v - 1000].size(); i++){
				if(level[g[v - 1000][i] - 1000] > level[v - 1000] + 1){
					level[g[v - 1000][i] - 1000] = level[v - 1000] + 1;
					q.push(g[v - 1000][i]);
				}
			}
		}
		
		if(level[B - 1000] == INF){
			printf("Impossible\n");
		}else{
			printf("%d\n", level[B - 1000]);
		}
	}
	
	return 0;
	
}


