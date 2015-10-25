//poj2376.cpp
//PKU JudgeOnline
//poj2376 Cleaning Shifts

#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <utility>
#define NMAX 25000
using namespace std;

typedef pair<int, int> Interval;


bool comp(Interval i1, Interval i2);

int N = 0;
int T = 0;
Interval cow[NMAX];
int ans = 0;

int main(int argc, char* argv[]){
	
	string ifn;
	string ofn;
	FILE* ifp = NULL;
	FILE* ofp = NULL;
	bool isFile = true;
	int now = 0;
	int p = 0;
	int tmp = 0;
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
	
	if(ifp != NULL){
		fscanf(ifp, "%d %d", &N, &T);
		for(i = 0; i < N; i++){
			fscanf(ifp, "%d %d", &(cow[i].first), &(cow[i].second));
		}
	}else{
		scanf("%d %d", &N, &T);
		for(i = 0; i < N; i++){
			scanf("%d %d", &(cow[i].first), &(cow[i].second));
		}
	}
	
	sort(cow, cow + N, comp);
	/* テスト****************************** */
//	for(i = 0; i < N; i++){
//		printf("%d, %d\n", cow[i].first, cow[i].second);
//	}
	/* ****************************** */
	
	ans = 0;
	now = 0;
	i = 0;
	while(i < N){
		tmp = 0;
		p = -1;
		while(i < N && cow[i].first <= now + 1){
			if(cow[i].second > tmp){
				tmp = cow[i].second;
				p = i;
			}
			i++;
		}
		if(p == -1){
			ans = -1;
			break;
		}
		now = cow[p].second;
		ans++;
	}
	
	if(now < T){
		ans = -1;
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

bool comp(Interval i1, Interval i2){
	return i1.first < i2.first;
}

