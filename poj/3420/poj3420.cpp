//poj3420.cpp
//PKU JudgeOnline
//poj3420 Quad Tiling

#include <cstdio>
#define D 13
using namespace std;


class Determinant{
	public:
		int val[D][D];
};

Determinant operator*(Determinant d1, Determinant d2);
Determinant pow(Determinant d, int n);

int N = 1;
int M = 1;
Determinant d;
int ans = 0;

int main(int argc, char* argv[]){
	//					 a  b  c  d  e  f  g  h  i  j  k  l  m
	int tmpval[D][D] = {{1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
						{1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
						{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
						{1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
						{0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
						{1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
						{0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
						{1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
						{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
						{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
						{0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
						{0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
						{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}};
	int v[D] = 			{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1};
	int s[5] = {0, 2, 4, 6, 12};
	int i, j;
	
	scanf("%d %d", &N, &M);
	while(N != 0){
		for(i = 0; i < D; i++){
			for(j = 0; j < D; j++){
				d.val[i][j] = tmpval[i][j];
			}
		}
		
		if(N == 1){
			ans = 1;
		}else{
			d = pow(d, N - 2);
			ans = 0;
			for(i = 0; i < 5; i++){
				for(j = 0; j < D; j++){
					ans = (ans + d.val[s[i]][j] * v[j]) % M;
				}
			}
		}
		
		printf("%d\n", ans);
		
		scanf("%d %d", &N, &M);
	}
	
	return 0;
	
}

Determinant operator*(Determinant d1, Determinant d2){
	Determinant d;
	int i, j, k;
	
	for(i = 0; i < D; i++){
		for(j = 0; j < D; j++){
			d.val[i][j] = 0;
			for(k = 0; k < D; k++){
				d.val[i][j] = (d.val[i][j] + d1.val[i][k] * d2.val[k][j]) % M;
			}
		}
	}
	
	return d;
}

Determinant pow(Determinant d, int n){
	
	Determinant tmpD;
	int i;
	
	for(i = 0; i < D; i++){
		tmpD.val[i][i] = 1;
	}
	while(n > 0){
		if((n & 1) == 1){
			tmpD = tmpD * d;
		}
		d = d * d;
		n = n >> 1;
	}
	
	return tmpD;
}

