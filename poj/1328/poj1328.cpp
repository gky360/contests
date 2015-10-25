//poj1328.cpp
//PKU JudgeOnline
//poj1328 Radar Installation

#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#define NMAX 1000
using namespace std;

typedef pair<int, int>XY;


bool comp(XY xy1, XY xy2);

int N = 0;
int D = 0;
XY ild[NMAX];
int ans = 0;

int main(int argc, char* argv[]){
	
	string ifn;
	string ofn;
	FILE* ifp = NULL;
	FILE* ofp = NULL;
	bool isFile = true;
	int a = 0;
	int b = 0;
//	int x = 0;
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
	
	j = 0;
	while(true){
		j++;
		if(ifp != NULL){
			fscanf(ifp, "%d %d", &N, &D);
			for(i = 0; i < N; i++){
				fscanf(ifp, "%d %d", &ild[i].first, &ild[i].second);
			}
		}else{
			scanf("%d %d", &N, &D);
//			printf("N = %d, D = %d\n", N, D);
			for(i = 0; i < N; i++){
				scanf("%d %d", &ild[i].first, &ild[i].second);
//				printf("%d, %d\n", ild[i].first, ild[i].second);
			}
		}
		if(N == 0){
			break;
		}
		
		ans = 0;
		for(i = 0; i < N; i++){
			if(ild[i].second > D){
				ans = -1;
				break;
			}
			a = ild[i].first;
			b = (int)sqrt((long double)(D * D - ild[i].second * ild[i].second));
			ild[i].first = a - b;
			ild[i].second = a + b;
		}
		if(ans == -1){
			if(ofp != NULL){
				fprintf(ofp, "Case %d: %d\n", j, ans);
			}
			printf("Case %d: %d\n", j, ans);
			continue;
		}
		
		sort(ild, ild + N, comp);
		
		i = 0;
		while(i < N){
			a = ild[i].second;
			b = i;
			while(i < N && ild[i].first <= a){
				if(ild[i].second < a){
					a = ild[i].second;
				}
				i++;
			}
			
			ans++;
		}
		
		
		
		
		/*
		sort(ild, ild + N, comp);
		
		ans = 0;
		a = ild[0].first;
		b = ild[0].second;
		if(b > D){
			ans = -1;
			if(ofp != NULL){
				fprintf(ofp, "Case %d: %d\n", j, ans);
			}
			printf("Case %d: %d\n", j, ans);
			continue;
		}
		x = a + (int)sqrt((long double)(D * D - b * b));
		ans++;
		
		for(i = 1; i < N; i++){
			a = ild[i].first;
			b = ild[i].second;
//			printf("%d:x = %d\n", i, x);
			if(b > D){
				ans = -1;
				break;
			}else if((a - x) * (a - x) + b * b <= D * D){
				continue;
			}
			
			x = a + (int)sqrt((long double)(D * D - b * b));
			ans++;
		}*/
		
		if(ofp != NULL){
			fprintf(ofp, "Case %d: %d\n", j, ans);
		}
		printf("Case %d: %d\n", j, ans);
	}
	
	if(ifp != NULL){
		fclose(ifp);
	}
	if(ofp != NULL){
		fclose(ofp);
	}
	
	return 0;
	
}

bool comp(XY xy1, XY xy2){
	return xy1.first < xy2.first;
}

