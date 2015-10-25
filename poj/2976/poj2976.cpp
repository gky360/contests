//poj2976.cpp
//PKU JudgeOnline
//poj2976 Dropping tests

#include <cstdio>
#include <cstdlib>
#include <string>
#include <utility>
#include <algorithm>
#define NMAX 1000
using namespace std;


bool comp(pair<int, int> p1, pair<int, int> p2);

int N = 0;
int K = 0;
pair<int ,int> test[NMAX];
double l = 0.0;
double r = 0.0;
double m = 0.0;
int ans = 0;

int main(int argc, char* argv[]){
	
	string ifn;
	string ofn;
	FILE* ifp = NULL;
	FILE* ofp = NULL;
	bool isFile = true;
	long long sa;
	long long sb;
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
			fscanf(ifp, "%d %d", &N, &K);
			for(i = 0; i < N; i++){
				fscanf(ifp, "%d", &test[i].first);
			}
			for(i = 0; i < N; i++){
				fscanf(ifp, "%d", &test[i].second);
			}
		}else{
			scanf("%d %d", &N, &K);
			for(i = 0; i < N; i++){
				scanf("%d", &test[i].first);
			}
			for(i = 0; i < N; i++){
				scanf("%d", &test[i].second);
			}
		}
		if(N == 0){
			break;
		}
		
		l = 0;
		r = 100;
		for(j = 0; j < 100; j++){
			m = (l + r) / 2;
			
			sort(test, test + N, comp);
			
			sa = 0;
			sb = 0;
			for(i = 0; i < N - K; i++){
				sa += test[i].first;
				sb += test[i].second;
			}
			if(100 * sa - m * sb >= 0){
				l = m;
			}else{
				r = m;
			}
		}
		
		ans = (int)(m + 0.5);
		
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

bool comp(pair<int, int> p1, pair<int, int> p2){
	double tmpd1 = 100 * p1.first - m * p1.second;
	double tmpd2 = 100 * p2.first - m * p2.second;
	return tmpd1 > tmpd2;
}

