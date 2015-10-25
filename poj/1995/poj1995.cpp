//poj1995.cpp
//PKU JudgeOnline
//poj1995 Raising Modulo Numbers

#include <cstdio>
using namespace std;


int Z;
int M;
int H;
int ans;

int main(){
	
	int a, b;
	int tmp;
	int i, j, k;
	
	scanf("%d", &Z);
	for(k = 0; k < Z; k++){
		scanf("%d", &M);
		scanf("%d", &H);
		ans = 0;
		for(j = 0; j < H; j++){
			scanf("%d %d", &a, &b);
			a %= M;
			tmp = 1;
			for(i = 1; i <= b; i <<= 1){
				if((b & i) > 0){
					tmp = (tmp * a) % M;
				}
				a = (a * a) % M;
			}
			ans = (ans + tmp) % M;
		}
		printf("%d\n", ans);
	}
	
	return 0;
	
}

