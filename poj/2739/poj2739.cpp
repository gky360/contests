//poj2839.cpp
//PKU JudgeOnline
//poj2739 Sum of Consecutive Prime Numbers

#include <cstdio>
#include <cstring>
#include <vector>
#define NMAX 10000
using namespace std;


int N;
vector<int> prime;
int ans;

int main(){
	
	bool table[NMAX + 1];
	int sum;
	int i, j;
	
	memset(table, 0, sizeof(table));
	for(i = 2; i * i <= NMAX; i++){
		if(table[i]){
			continue;
		}
		for(j = i * 2; j <= NMAX; j += i){
			table[j] = true;
		}
	}
	for(i = 2; i <= NMAX; i++){
		if(!table[i]){
			prime.push_back(i);
		}
	}
	
	while(true){
		
		scanf("%d", &N);
		if(N == 0){
			break;
		}
		
		ans = 0;
		sum = 0;
		j = 0;
		for(i = 0; i < (int)prime.size(); i++){
			sum += prime[i];
			while(sum > N){
				sum -= prime[j];
				j++;
			}
			if(sum == N){
				ans++;
			}
		}
		
		printf("%d\n", ans);
		
	}
	
	return 0;
	
}


