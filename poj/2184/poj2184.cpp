//poj2184.cpp
//PKU JudgeOnline
//poj2184 Cow Exhibition

#include <cstdio>
#include <cstdlib>
#include <string>
#define NMAX 100
#define FMAX 1000
using namespace std;


const int INF = (1 << 31) - 1;
int N = 0;
int s[NMAX];
int f[NMAX];
int dp[NMAX][2 * FMAX + 1];
int ts = 0;
int tf = 0;
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
	
	if(ifp != NULL){
		fscanf(ifp, "%d", &N);
		for(i = 0; i < N; i++){
			fscanf(ifp, "%d %d", &s[i], &f[i]);
		}
	}else{
		scanf("%d", &N);
		for(i = 0; i < N; i++){
			scanf("%d %d", &s[i], &f[i]);
		}
	}
	
//	printf("INF = %d\n", INF);
	for(i = 0; i < N; i++){
		for(j = -FMAX; j <= FMAX; j++){
			dp[i][j + FMAX] = -INF;
		}
	}
	
	dp[0][f[0] + FMAX] = s[0];
	for(i = 1; i < N; i++){
		for(j = -FMAX; j <= FMAX; j++){
			if(j - f[i] < -FMAX || FMAX < j - f[i] || dp[i - 1][j - f[i] + FMAX] == -INF){
				dp[i][j + FMAX] = dp[i - 1][j + FMAX];
			}else{
				dp[i][j + FMAX] = max(dp[i - 1][j - f[i] + FMAX] + s[i], dp[i - 1][j + FMAX]);
			}
		}
		dp[i][f[i] + FMAX] = max(dp[i][f[i] + FMAX], s[i]);
	}
	
/*	for(j = -11; j <= 8; j++){
		printf("%3d ", j);
	}
	printf("\n");
	for(i = 0; i < N; i++){
		for(j = -11; j <= 8; j++){
			if(dp[i][j + FMAX] == -INF){
				printf("  - ");
			}else{
				printf("%3d ", dp[i][j + FMAX]);
			}
		}
		printf("\n");
	}
*/	
	ans = 0;
	for(tf = 0; tf <= FMAX; tf++){
		ts = dp[N - 1][tf + FMAX];
		if(ts >= 0 && ts + tf > ans){
			ans = ts + tf;
		}
	}
	
	if(ofp != NULL){
		fprintf(ofp, "%d\n", ans);
	}
	printf("%d\n", ans);
	
	if(ifp != NULL){
		fclose(ifp);
	}
	if(ofp != NULL){
		fclose(ofp);
	}
	
	return 0;
	
}

