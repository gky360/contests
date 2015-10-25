//poj3176.cpp
//PKU JudgeOnline
//poj3176 Cow Bowling

#include <cstdio>
#include <algorithm>
#define NMAX 350
using namespace std;


int N;
int table[NMAX][NMAX];

int main(){
	
	int i, j;
	
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		for(j = 0; j < i + 1; j++){
			scanf("%d", &table[i][j]);
		}
	}
	
	for(i = N - 2; i >= 0; i--){
		for(j = 0; j < i + 1; j++){
			table[i][j] += max(table[i + 1][j], table[i + 1][j + 1]);
		}
	}
	
	printf("%d\n", table[0][0]);
	
	return 0;
	
}

