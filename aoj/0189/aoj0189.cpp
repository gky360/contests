//aoj0189.cpp
//AIZU ONLINE JUDGE
//aoj0189 Convenient Location

#include <cstdio>
#include <algorithm>
#define VMAX 10
#define INF 1 << 28
using namespace std;


int N;
int V;
int d[VMAX][VMAX];
int ans_town, ans_sum;

int main(){
	
	int sum;
	int a, b, c;
	int i, j, k;
	
	while(true){
		scanf("%d", &N);
		if(N == 0){
			break;
		}
		for(i = 0; i < VMAX; i++){
			for(j = 0; j < VMAX; j++){
				d[i][j] = INF;
			}
		}
		V = 0;
		for(i = 0; i < N; i++){
			scanf("%d %d %d", &a, &b, &c);
			d[a][b] = min(d[a][b], c);
			d[b][a] = min(d[b][a], c);
			V = max(V, max(a, b));
		}
		V++;
		for(i = 0; i < V; i++){
			d[i][i] = 0;
		}
		
		for(k = 0; k < V; k++){
			for(i = 0; i < V; i++){
				for(j = 0; j < V; j++){
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
		
		ans_sum = INF;
		for(i = 0; i < V; i++){
			sum = 0;
			for(j = 0; j < V; j++){
				sum += d[i][j];
			}
			if(ans_sum > sum){
				ans_town = i;
				ans_sum = sum;
			}
		}
		
		printf("%d %d\n", ans_town, ans_sum);
		
	}
	
	return 0;
	
}


