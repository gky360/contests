//poj3734.cpp
//PKU JudgeOnline
//poj3734 Blocks

#include <cstdio>
#define D 3
#define V 10007
using namespace std;


class Determinant{
	public:
		int val[D][D];
		Determinant();
};

Determinant::Determinant(){
	int i, j;
	
	for(i = 0; i < D; i++){
		for(j = 0; j < D; j++){
			val[i][j] = 0;
		}
		val[i][i] = 1;
	}
	
	return;
}

Determinant operator*(Determinant d1, Determinant d2);
Determinant pow(Determinant d, int n);

int N;
int T;
Determinant d;
int tmpval[D][D] = {{2, 1, 0},
					{2, 2, 2},
					{0, 1, 2}};
int v[D] = {1, 0, 0};
int ans = 0;

int main(){
	
	int i, j, k;
	
	scanf("%d", &T);
	for(k = 0; k < T; k++){
		scanf("%d", &N);
		for(i = 0; i < D; i++){
			for(j = 0; j < D; j++){
				d.val[i][j] = tmpval[i][j];
			}
		}
		d = pow(d, N);
		ans = 0;
		for(j = 0; j < D; j++){
			ans = (ans + d.val[0][j] * v[j]) % V;
		}
		printf("%d\n", ans);
	}
	
}

Determinant operator*(Determinant d1, Determinant d2){
	Determinant d;
	int i, j, k;
	
	for(i = 0; i < D; i++){
		for(j = 0; j < D; j++){
			d.val[i][j] = 0;
			for(k = 0; k < D; k++){
				d.val[i][j] = (d.val[i][j] + d1.val[i][k] * d2.val[k][j]) % V;
			}
		}
	}
	
	return d;
}

Determinant pow(Determinant d, int n){
	Determinant tmpD;
	
	while(n > 0){
		if((n & 1) == 1){
			tmpD = tmpD * d;
		}
		d = d * d;
		n = n >> 1;
	}
	
	return tmpD;
}

