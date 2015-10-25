//poj2010.cpp
//PKU JudgeOnline
//poj2010 Moo University - Financial Aid

#include <cstdio>
#include <cstdlib>
#include <string>
#include <queue>
#include <algorithm>
#define CMAX 100000
using namespace std;


class SA{
public:
	int score;
	int aid;
private:
public:
private:
};

bool operator <(SA sa1, SA sa2);
bool comp(SA sa1, SA sa2);

int N = 0;
int C = 0;
int F = 0;
SA cow[CMAX];
priority_queue<SA> q;
int d1[CMAX];	/* 0からiまでのうちN/2個のaidの和の最小値 */
int d2[CMAX];	/* iからCまでのうちN/2個のaidの和の最小値 */
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
	
	if(ifp != NULL){
		fscanf(ifp, "%d %d %d", &N, &C, &F);
		for(i = 0; i < C; i++){
			fscanf(ifp, "%d %d", &cow[i].score, &cow[i].aid);
		}
	}else{
		scanf("%d %d %d", &N, &C, &F);
		for(i = 0; i < C; i++){
			scanf("%d %d", &cow[i].score, &cow[i].aid);
		}
	}
	
	sort(cow, cow + C, comp);
	
	d1[N / 2] = 0;
	for(i = 0; i < N / 2; i++){
		d1[N / 2] += cow[i].aid;
		q.push(cow[i]);
	}
//	printf("d1[%d] = %d\n", i, d1[i]);
	for(i = max(N / 2 + 1, 1); i < C - N / 2; i++){
		q.push(cow[i - 1]);
		d1[i] = d1[i - 1] + cow[i - 1].aid - q.top().aid;
		q.pop();
//		printf("d1[%d] = %d\n", i, d1[i]);
	}
	while(!q.empty()){
		q.pop();
	}
	
	d2[C - N / 2 - 1] = 0;
	for(i = C - 1; i >= C - N / 2; i--){
		d2[C - N / 2 - 1] += cow[i].aid;
		q.push(cow[i]);
	}
//	printf("d2[%d] = %d\n", i, d2[i]);
	for(i = min(C - N / 2 - 2, C - 2); i >= N / 2; i--){
		q.push(cow[i + 1]);
		d2[i] = d2[i + 1] + cow[i + 1].aid - q.top().aid;
		q.pop();
//		printf("d2[%d] = %d\n", i, d2[i]);
	}
	
	ans = -1;
	for(i = N / 2; i < C - N / 2; i++){
		if(d1[i] + cow[i].aid + d2[i] <= F){
			ans = cow[i].score;
			break;
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

bool operator <(SA sa1, SA sa2){
	return sa1.aid < sa2.aid;
}

bool comp(SA sa1, SA sa2){
	return sa1.score > sa2.score || (sa1.score == sa2.score && sa1.aid < sa2.aid);
}

