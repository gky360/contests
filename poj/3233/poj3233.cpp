//poj3233.cpp
//PKU JudgeOnline
//poj3233 Matrix Power Series

#include <cstdio>
#define NMAX 30
using namespace std;


class Matrix{
	public:
		int val[2 * NMAX][2 * NMAX];
		Matrix();
};

Matrix::Matrix(){
	int i, j;
	
	for(i = 0; i < 2 * NMAX; i++){
		for(j = 0; j < 2 * NMAX; j++){
			val[i][j] = 0;
		}
		val[i][i] = 1;
	}
	
	return;
}

Matrix operator*(Matrix m1, Matrix m2);
Matrix pow(Matrix m, int n);

int N = 0;
int K = 0;
int M = 1;
Matrix m;

int main(){
	
	int tmp;
	int i, j;
	
	scanf("%d %d %d", &N, &K, &M);
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			scanf("%d", &tmp);
			m.val[i][j] = 0;
			m.val[i + N][j] = 0;
			m.val[i][j + N] = tmp;
			m.val[i + N][j + N] = tmp;
		}
		m.val[i][i] = 1;
	}
	
	m = pow(m, K);
	
	for(i = 0; i < N; i++){
		printf("%d", m.val[i][0 + N]);
		for(j = 1; j < N; j++){
			printf(" %d", m.val[i][j + N]);
		}
		printf("\n");
	}
	
	return 0;
}

Matrix operator*(Matrix m1, Matrix m2){
	Matrix m;
	int i, j, k;
	
	for(i = 0; i < 2 * N; i++){
		for(j = 0; j < 2 * N; j++){
			m.val[i][j] = 0;
			for(k = 0; k < 2 * N; k++){
				m.val[i][j] = (m.val[i][j] + m1.val[i][k] * m2.val[k][j]) % M;
			}
		}
	}
	
	return m;
	
}

Matrix pow(Matrix m, int n){
	Matrix tmpM;
	
	while(n > 0){
		if((n & 1) == 1){
			tmpM = tmpM * m;
		}
		m = m * m;
		n = n >> 1;
	}
	
	return tmpM;
}

