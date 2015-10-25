//poj3614.cpp
//PKU JudgeOnline
//poj3614 Sunscreen

#include <cstdio>
#include <cstdlib>
#include <string>
#include <queue>
#include <algorithm>
#define CMAX 2500
#define LMAX 2500
using namespace std;


class CL{
public:
	int first;
	int second;
};

bool operator <(CL cl1, CL cl2);
bool comp(CL cl1, CL cl2);

int C = 0;
int L = 0;
CL cow[CMAX];
CL lotion[LMAX];
priority_queue<CL> q;
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
		fscanf(ifp, "%d %d", &C, &L);
		for(i = 0; i < C; i++){
			fscanf(ifp, "%d %d", &cow[i].first, &cow[i].second);
		}
		for(i = 0; i < L; i++){
			fscanf(ifp, "%d %d", &lotion[i].first, &lotion[i].second);
		}
	}else{
		scanf("%d %d", &C, &L);
		for(i = 0; i < C; i++){
			scanf("%d %d", &cow[i].first, &cow[i].second);
		}
		for(i = 0; i < L; i++){
			scanf("%d %d", &lotion[i].first, &lotion[i].second);
		}
	}
	
	sort(cow, cow + C, comp);
	sort(lotion, lotion + L, comp);
	
	ans = 0;
	i = 0;
	for(j = 0; j < L; j++){
		while(cow[i].first <= lotion[j].first){
			q.push(cow[i]);
			i++;
		}
		while(!q.empty() && lotion[j].second > 0){
			if(q.top().second >= lotion[j].first){
				ans++;
				lotion[j].second--;
			}
			q.pop();
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

bool operator <(CL cl1, CL cl2){
	return cl1.second > cl2.second;
}

bool comp(CL cl1, CL cl2){
	return cl1.first < cl2.first;
}

