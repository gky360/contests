//poj3111.cpp
//PKU JudgeOnline
//poj3111 K Best

#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#define NMAX 1000000
using namespace std;


class Jewel{
public:
	int v;
	int w;
	int n;
private:
public:
private:
};

bool operator <(Jewel j1, Jewel j2);

int N = 0;
int K = 0;
Jewel vw[NMAX];
double l = 0.0;
double r = 0.0;
double m = 0.0;

int main(int argc, char* argv[]){
	
	string ifn;
	string ofn;
	FILE* ifp = NULL;
	FILE* ofp = NULL;
	bool isFile = true;
	int sv = 0;
	int sw = 0;
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
		fscanf(ifp, "%d %d", &N, &K);
		for(i = 0; i < N; i++){
			fscanf(ifp, "%d %d", &vw[i].v, &vw[i].w);
			vw[i].n = i + 1;
		}
	}else{
		scanf("%d %d", &N, &K);
		for(i = 0; i < N; i++){
			scanf("%d %d", &vw[i].v, &vw[i].w);
			vw[i].n = i + 1;
		}
	}
	
	l = 0;
	r = 1000000;
	for(j = 0; j < 100; j++){
		m = (l + r) / 2;
		
		sort(vw, vw + N);
		
		sv = 0;
		sw = 0;
		for(i = 0; i < K; i++){
			sv += vw[i].v;
			sw += vw[i].w;
		}
		if(sv - m * sw >= 0){
			l = m;
		}else{
			r = m;
		}
	}
	
	if(ofp != NULL){
		fprintf(ofp, "%d", vw[0].n);
		for(i = 1; i < K; i++){
			fprintf(ofp, " %d", vw[i].n);
		}
		fprintf(ofp, "\n");
	}
	printf("%d", vw[0].n);
	for(i = 1; i < K; i++){
		printf(" %d", vw[i].n);
	}
	printf("\n");
	
	if(ifp != NULL){
		fclose(ifp);
	}
	if(ofp != NULL){
		fclose(ofp);
	}
	
	return 0;
	
}

bool operator <(Jewel j1, Jewel j2){
	return j1.v - m * j1.w > j2.v - m * j2.w;
}

