//poj3187.cpp
//PKU JudgeOnline
//poj3187 Backward Digit Sums

#include <cstdio>
#include <algorithm>
#define NMAX 10
using namespace std;


int N;
int sum;
int digit[NMAX];
int pasc[NMAX];	//パスカルの三角形

int main(){
	
	int tmp;
	int i, j;
	
	scanf("%d %d", &N, &sum);
	for(i = 0; i < N; i++){
		digit[i] = i + 1;
		pasc[i] = 0;
	}
	pasc[0] = 1;
	for(j = 0; j < N - 1; j++){
		for(i = j + 1; i >= 1; i--){
			pasc[i] += pasc[i - 1];
		}
	}
	
	do{
		tmp = 0;
		for(i = 0; i < N; i++){
			tmp += pasc[i] * digit[i];
		}
		if(tmp == sum){
			break;
		}
	}while(next_permutation(digit, digit + N));
	
	for(i = 0; i < N; i++){
		printf("%d%c", digit[i], i == N - 1 ? '\n' : ' ');
	}
	
	return 0;
	
}

