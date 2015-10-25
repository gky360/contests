//poj1284.cpp
//PKU Judge Online
//poj1284 Primitive Roots

#include <cstdio>
#include <cstring>
#include <vector>
#define P_MAX 65536
using namespace std;


int P;
vector<int> prime;	// 素数の配列
bool table[P_MAX];
int ans;

int main(){
	
	int n;
	int tmp;
	int i, j;
	
	memset(table, 0, sizeof(table));
	for(i = 2; i < P_MAX; i++){	// エラトステネスの篩
		if(table[i]){
			continue;
		}
		prime.push_back(i);
		for(j = i * 2; j < P_MAX; j += i){
			table[j] = true;
		}
	}
	
	while(scanf("%d", &P) != -1){
		n = P - 1;
		ans = P - 1;
		tmp = 1;
		for(i = 0; prime[i] <= n; i++){
			if(n % prime[i] != 0){
				continue;
			}
			ans *= prime[i] - 1;
			tmp *= prime[i];
			while(n % prime[i] == 0){
				n /= prime[i];
			}
		}
		ans /= tmp;
		printf("%d\n", ans);
	}
	
	return 0;
	
}

