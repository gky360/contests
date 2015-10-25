//poj1742.cpp
//PKU JudgeOnline
//poj1742 Coins

#include <cstdio>
#include <cstdlib>
#include <string>
#define NMAX 100
#define MMAX 100000
using namespace std;


int N = 0;
int M = 0;
int a[NMAX];
int c[MMAX];
int dp[MMAX + 1];
int ans = 0;

int main(int argc, char* argv[]){
	
	string ifn;
	string ofn;
	FILE* ifp = NULL;
	FILE* ofp = NULL;
	bool isFile = true;
	int i = 0;
	int j = 0;
	
	if(argc == 3){
		ifn = argv[1];
		ofn = argv[2];
	}else if(argc == 2){
		ifn = argv[1];
		ofn = "output.txt";
	}else{
		isFile = false;
	}
	
	if(isFile){
		ifp = fopen(ifn.c_str(), "r");
		if(ifp == NULL){
			printf("入力ファイル %s を開けませんでした。", ifn.c_str());
			return -1;
		}
		ofp = fopen(ofn.c_str(), "w");
		if(ofp == NULL){
			printf("出力ファイル %s を開けませんでした。", ofn.c_str());
			return -1;
		}
	}
	
	while(true){
		if(ifp != NULL){
			fscanf(ifp, "%d %d", &N, &M);
			for(i = 0; i < N; i++){
				fscanf(ifp, "%d", &a[i]);
			}
			for(i = 0; i < N; i++){
				fscanf(ifp, "%d", &c[i]);
			}
		}else{
			scanf("%d %d", &N, &M);
			for(i = 0; i < N; i++){
				scanf("%d", &a[i]);
			}
			for(i = 0; i < N; i++){
				scanf("%d", &c[i]);
			}
		}
		if(N == 0){
			break;
		}
		
		for(i = 0; i <= M; i++){
			dp[i] = -1;
		}
		
		for(i = 0; i < N; i++){
			dp[0] = c[i];
			for(j = 1; j <= M; j++){
				if(dp[j] >= 0){
					dp[j] = c[i];
				}else if(j >= a[i] && dp[j - a[i]] > 0){
					dp[j] = dp[j - a[i]] - 1;
				}else{
					dp[j] = -1;
				}
			}
/*			for(j = 0; j <= M; j++){
				printf("%2d ", dp[j]);
			}
			printf("\n");
*/		}
		
		ans = 0;
		for(i = 1; i <= M; i++){
			if(dp[i] >= 0){
				ans++;
			}
		}
		
		if(ofp != NULL){
			fprintf(ofp, "%d\n", ans);
		}
		printf("%d\n", ans);
		
	}
	
	
	
	if(ifp != NULL){
		fclose(ifp);
	}
	if(ofp != NULL){
		fclose(ofp);
	}
	
	return 0;
	
}

