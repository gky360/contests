//poj2386.cpp
//PKU JudgeOnline
//poj2386 Lake Counting

#include <cstdio>
#include <queue>
#define NMAX 100
#define MMAX 100
using namespace std;


int N = 0;
int M = 0;
char f[NMAX + 2][MMAX + 2];
queue<int> qn;
queue<int> qm;
int vn[3] = {-1, 0, 1};
int vm[3] = {-1, 0, 1};
int ans = 0;

int main(){
	
	int n = 0;
	int m = 0;
	int k = 0;
	int l = 0;
	int i = 0;
	int j = 0;
	
	scanf("%d %d", &N, &M);
	
	for(i = 1; i <= N; i++){
		scanf("%s", &f[i][1]);
	}
	for(i = 0; i <= N + 1; i++){
		f[i][0] = '.';
		f[i][M + 1] = '.';
	}
	for(j = 0; j <= M + 1; j++){
		f[0][j] = '.';
		f[N + 1][j] = '.';
	}
	
	for(i = 1; i <= N; i++){
		for(j = 1; j <= M; j++){
			if(f[i][j] == 'W'){
				n = i;
				m = j;
				qn.push(n);
				qm.push(m);
				f[n][m] = ',';
				while(!qn.empty()){
					n = qn.front();
					m = qm.front();
					qn.pop();
					qm.pop();
					for(k = 0; k < 3; k++){
						for(l = 0; l < 3; l++){
							if(f[n + vn[k]][m + vm[l]] == 'W'){
								qn.push(n + vn[k]);
								qm.push(m + vm[l]);
								f[n + vn[k]][m + vm[l]] = '.';
							}
						}
					}
				}
				ans++;
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
	
}

