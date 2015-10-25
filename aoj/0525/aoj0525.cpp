//aoj0525.cpp
//AIZU ONLINE JUDGE
//aoj0525 Osenbei

#include <cstdio>
#include <algorithm>
#define RMAX 10
#define CMAX 10000
using namespace std;


int R;
int C;
int table[RMAX][CMAX];
int ans;

int main(){
	
	int tmp, tmp_col;
	int i, j, k;
	
	while(true){
		scanf("%d %d", &R, &C);
		if(R == 0){
			break;
		}
		for(i = 0; i < R; i++){
			for(j = 0; j < C; j++){
				scanf("%d", &table[i][j]);
			}
		}
		
		ans = 0;
		for(k = 0; k < (1 << (R - 1)); k++){
			tmp = 0;
			for(j = 0; j < C; j++){
				tmp_col = 0;
				for(i = 0; i < R; i++){
					tmp_col += (table[i][j] + (1 & (k >> i))) % 2;
				}
				tmp += max(tmp_col, R - tmp_col);
			}
			ans = max(ans, tmp);
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
	
}




