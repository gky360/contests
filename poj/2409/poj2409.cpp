//poj2409.cpp
//PKU Judge Online
//poj2409 Let it Bead

#include <cstdio>
#include <cmath>
#include <set>
#define S_MAX 32
using namespace std;


int C;
int S;
set<int> symmetry;
int ans;

int gcd(int a, int b){
	if(b == 0){
		return a;
	}
	return gcd(b, a % b);
}

void symm_bra(int r, int* tmp, int k){	// 左右対称のブレスレット生成。作業用braceletのアドレスを渡す
										// k=0:点軸反転, k=1:辺軸反転
	int num, tmp_num;
	int bace;
	int i, j;
	
	if(r == (S + 2 - k) / 2){
		num = 0;
		for(j = 0; j < S; j++){
			tmp_num = 0;
			bace = 1;
			for(i = 0; i < S; i++){
				tmp_num += tmp[(i + j) % S] * bace;
				bace *= C;
			}
			num = max(num, tmp_num);
		}
		
		symmetry.insert(num);
		
		return;
	}
	
	for(i = 0; i < C; i++){
		tmp[r] = i;
		if(S - r - k < S){
			tmp[S - r - k] = i;
		}
		symm_bra(r + 1, tmp, k);
	}
	return;
}

int main(){
	
	int polya;
	int tmp[S_MAX];
	int i;
	
	while(true){
		scanf("%d %d", &C, &S);
		if(C == 0){
			break;
		}
		
		polya = 0;
		for(i = 0; i < S; i++){
			polya += pow(C, gcd(S, i));
		}
		polya /= S;
		
		symm_bra(0, tmp, 0);
		if(S % 2 == 0){
			symm_bra(0, tmp, 1);
		}
		
		ans = (polya - symmetry.size()) / 2 + symmetry.size();
		
		printf("%d\n", ans);
		
		symmetry.clear();
	}
	
	return 0;
	
}

