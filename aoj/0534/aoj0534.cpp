//aoj0534.cpp
//会津大学オンラインジャッジ
//aoj0534 Chain

#include <cstdio>
#include <algorithm>
#define NMAX 10000
using namespace std;


int solve(int l, int r);

int N, M;
int p[NMAX + 2][3];
int ans;

int main(){
	
	int tmp;
	int i, j;
	
	scanf("%d", &N);
	while(N != 0){
		ans = N;
		p[0][0] = p[0][1] = p[0][2] = 0;
		j = 0;
		for(i = 0; i < N; i++){
			scanf("%d", &tmp);
			if(tmp != p[j][0]){
				j++;
				p[j][0] = tmp;
				p[j][1] = 1;
			}else{
				p[j][1]++;
			}
		}
		M = j;
		p[M + 1][0] = p[M + 1][1] = p[M + 1][2] = 0;
		for(i = 1; i <= M; i++){
			p[i][2] = p[i - 1][2] + p[i][1];
		}
		p[0][1] = p[M + 1][1] = -4;
		
		for(i = 1; i <= M; i++){
			if(p[i][1] == 1 && p[i - 1][0] == p[i + 1][0]){
				if(p[i - 1][1] + p[i + 1][1] >= 3){
					ans = min(ans, solve(i - 1, i + 1));
				}
			}else{
				p[i][1]--;
				if(p[i - 1][1] >= 3){
					ans = min(ans, solve(i - 1, i - 1));
				}
				if(p[i + 1][1] >= 3){
					ans = min(ans, solve(i + 1, i + 1));
				}
				p[i][1]++;
			}
		}
		printf("%d\n", ans);
		
		scanf("%d", &N);
	}
	
	return 0;
	
}

int solve(int l, int r){
	l--;
	r++;
	if(p[l][1] == 0){
		l--;
	}
	if(p[r][1] == 0){
		r++;
	}
	while(p[l][0] == p[r][0] && p[l][1] + p[r][1] >= 4){
		l--;
		r++;
	}
	return N - (p[r - 1][2] - p[l][2]);
}

