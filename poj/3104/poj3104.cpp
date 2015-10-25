//poj3104.cpp
//PKU JudgeOnline
//poj3104 Drying

#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#define NMAX 1000000
#define KMAX 1000000000
using namespace std;


int lb(int l, int r);

int N = 0;
int shirt[NMAX];
int K = 0;
int ans = 0;

int main(int argc, char* argv[]){
	
	string ifn;
	string ofn;
	FILE* ifp = NULL;
	FILE* ofp = NULL;
	bool isFile = true;
	int i = 0;
	
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
			fscanf(ifp, "%d", &N);
			if(N == 0){
				break;
			}
			for(i = 0; i < N; i++){
				fscanf(ifp, "%d", &shirt[i]);
			}
			fscanf(ifp, "%d", &K);
		}else{
			scanf("%d", &N);
			if(N == 0){
				break;
			}
			for(i = 0; i < N; i++){
				scanf("%d", &shirt[i]);
			}
			scanf("%d", &K);
		}
		
		sort(shirt, shirt + N);
		
		ans = lb(0, KMAX);
		
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

int lb(int l, int r){
	int m = (l + r) / 2;
	int sum = 0;
	bool tf = true;
	int i = 0;
	
	if(r - l == 1){
		return r;
	}
	
	sum = 0;
	for(i = upper_bound(shirt, shirt + N, m) - shirt; i < N; i++){
		sum += (shirt[i] - m + K - 1) / K;
		if(sum > m){
			tf = false;
			break;
		}
	}
	
	if(tf){
		r = m;
	}else{
		l = m;
	}
	return lb(l, r);
}

