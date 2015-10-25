//poj3190
//PKU JudgeOnline
//poj3190 Stall Reservations

#include <cstdio>
#include <cstdlib>
#include <string>
#include <queue>
#include <algorithm>
#define NMAX 50000
using namespace std;


class Itvl{
public:
	int first;
	int second;
	int n;
private:
public:
private:
};

bool operator <(Itvl c1, Itvl c2){
	return c1.second > c2.second;
}

bool comp1(Itvl c1, Itvl c2);
bool comp2(Itvl c1, Itvl c2);

int N = 0;
Itvl cow[NMAX];
int stall[NMAX];
priority_queue<Itvl> q;
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
		fscanf(ifp, "%d", &N);
		for(i = 0; i < N; i++){
			fscanf(ifp, "%d %d", &cow[i].first, &cow[i].second);
		}
	}else{
		scanf("%d", &N);
		for(i = 0; i < N; i++){
			scanf("%d %d", &cow[i].first, &cow[i].second);
		}
	}
	
	for(i = 0; i < N; i++){
		stall[i] = 0;
		cow[i].n = i;
	}
	
	sort(cow, cow + N, comp1);
	
	cow[0].first = 1;
	stall[cow[0].n] = 1;
	q.push(cow[0]);
	ans = 1;
	for(i = 1; i < N; i++){
		if(cow[i].first <= q.top().second){
			cow[i].first = ans + 1;
			stall[cow[i].n] = ans + 1;
			q.push(cow[i]);
			ans++;
		}else{
			cow[i].first = q.top().first;
			stall[cow[i].n] = q.top().first;
			q.pop();
			q.push(cow[i]);
		}
	}
	
	if(ofp != NULL){
		fprintf(ofp, "%d\n", ans);
		for(i = 0; i < N; i++){
			fprintf(ofp, "%d\n", stall[i]);
		}
	}
	printf("%d\n", ans);
	for(i = 0;i < N; i++){
		printf("%d\n", stall[i]);
	}
	
	if(ifp != NULL){
		fclose(ifp);
	}
	if(ofp != NULL){
		fclose(ofp);
	}
	
	return 0;
	
}

bool comp1(Itvl c1, Itvl c2){
	return c1.first < c2.first;
}

bool comp2(Itvl c1, Itvl c2){
	return c1.second < c2.second;
}

