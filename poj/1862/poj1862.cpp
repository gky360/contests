//poj1862.cpp
//PKU JudgeOnline
//poj1862 Stripes

#include <cstdio>
#include <cmath>
#include <algorithm>
#define NMAX 100
using namespace std;


int N;
double stripe[NMAX];
double ans;

int main(){
	
	int tmp;
	int i;
	
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%d", &tmp);
		stripe[i] = tmp;
	}
	
	sort(stripe, stripe + N);
	
	for(i = N - 2; i >= 0; i--){
		stripe[i] = 2 * sqrt(stripe[i] * stripe[i + 1]);
	}
	
	ans = stripe[0];
	printf("%.3f\n", ans);
	
	return 0;
	
}

