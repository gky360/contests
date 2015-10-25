//aoj0033.cpp
//会津大学オンラインジャッジ
//aoj0033 Ball

#include <cstdio>
#include <cstdlib>
#include <string>
#define BMAX 10
#define INF 1000
using namespace std;


int N = 0;
int ball[BMAX];
int tube[2] = {0, 0};
bool ans = true;

int main(int argc, char* argv[]){
	
	string ifn;
	string ofn;
	FILE* ifp = NULL;
	FILE* ofp = NULL;
	bool isFile = true;
	int d[2] = {0, 0};
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
	}else{
		scanf("%d", &N);
	}
	
	for(j = 0; j < N; j++){
		for(i = 0; i < BMAX; i++){
			if(ifp != NULL){
				fscanf(ifp, "%d", &ball[i]);
			}else{
				scanf("%d", &ball[i]);
			}
		}
		
		tube[0] = 1;
		tube[1] = 0;
		
		ans = true;
		for(i = 0; i < BMAX; i++){
			d[0] = ball[i] - tube[0];
			d[1] = ball[i] - tube[1];
			if(d[0] < 0){
				d[0] = INF;
			}
			if(d[1] < 0){
				d[1] = INF;
			}
			if(d[0] < d[1]){
				tube[0] = ball[i];
			}else if(d[1] < d[0]){
				tube[1] = ball[i];
			}else{
				ans = false;
				break;
			}
		}
		
		if(ans){
			if(ofp != NULL){
				fprintf(ofp, "YES\n");
			}
			printf("YES\n");
		}else{
			if(ofp != NULL){
				fprintf(ofp, "NO\n");
			}
			printf("NO\n");
		}
	}
	
	if(ifp != NULL){
		fclose(ifp);
	}
	if(ofp != NULL){
		fclose(ofp);
	}
	
	return 0;
	
}

