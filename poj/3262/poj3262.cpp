//poj3262.cpp
//PKU JudgeOnline
//poj3262 Protecting the Flowers

#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <utility>
#define NMAX 1000000
using namespace std;

typedef pair<int, int> TD;


bool comp(TD td1, TD td2);

int N = 0;
TD cow[NMAX];
long long ans = 0;

int main(int argc, char* argv[]){
	
	string ifn;
	string ofn;
	FILE* ifp = NULL;
	FILE* ofp = NULL;
	bool isFile = true;
	long long tmp = 0;
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
	
	sort(cow, cow + N, comp);
	
	ans = 0;
	tmp = 0;
	for(i = N - 1; i >= 0; i--){
		ans += 2 * cow[i].first * tmp;
		tmp += cow[i].second;
	}
	
	if(ofp != NULL){
		fprintf(ofp, "%lld\n", ans);
	}
	printf("%lld\n", ans);
	
	if(ifp != NULL){
		fclose(ifp);
	}
	if(ofp != NULL){
		fclose(ofp);
	}
	
	return 0;
	
}

bool comp(TD td1, TD td2){
	return td1.first * td2.second < td2.first * td1.second;
}

