//poj3040.cpp
//PKU JudgeOnline
//poj3040 Alloance

#include <cstdio>
#include <algorithm>
#include <utility>
#define NMAX 20
using namespace std;


int N;
int C;
pair<int, int> coin[NMAX];
int ans;

int main(){
	
	int num, sum;
	int i;
	
	scanf("%d %d", &N, &C);
	for(i = 0; i < N; i++){
		scanf("%d %d", &coin[i].first, &coin[i].second);
	}
	sort(coin, coin + N);
	
	ans = 0;
	while(true){
		sum = C;
		for(i = N - 1; i >= 0; i--){
			if(coin[i].first > sum || coin[i].second == 0){
				continue;
			}
			num = min(sum / coin[i].first, coin[i].second);
			sum -= coin[i].first * num;
			coin[i].second -= num;
		}
		if(sum > 0){
			for(i = 0; i < N; i++){
				if(coin[i].second > 0){
					sum -= coin[i].first;
					coin[i].second--;
					break;
				}
			}
		}
		
		if(sum > 0){
			break;
		}
		ans++;
	}
	
	printf("%d\n", ans);
	
	return 0;
	
}

