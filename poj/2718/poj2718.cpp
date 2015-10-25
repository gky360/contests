//poj2718.cpp
//PKU JudgeOnline
//poj2718 Smallest Difference

#include <cstdio>
#include <cstdlib>
#include <string>
#include <cctype>
using namespace std;


int M = 0;
int N = 0;
int num[10];
int power[10];
int ans = 0;

int main(int argc, char* argv[]){
	
	string ifn;
	string ofn;
	FILE* ifp = NULL;
	FILE* ofp = NULL;
	bool isFile = true;
	char buf[256];
	int tmp = 0;
	int idx = 0;
	int tmp1[10];
	int tmp2[10];
	int a = 0;
	int b = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	
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
	
	power[0] = 1;
	for(i = 1; i <= 9; i++){
		power[i] = power[i - 1] * 10;
	}
	
	if(ifp != NULL){
		fscanf(ifp, "%d\n", &M);
	}else{
		scanf("%d\n", &M);
	}
	
	for(k = 0; k < M; k++){
		if(ifp != NULL){
			fgets(buf, 256, ifp);
		}else{
			fgets(buf, 256, stdin);
		}
		
		j = 0;
		for(i = 0; buf[i] != '\0'; i++){
			if(isdigit(buf[i])){
				num[j] = buf[i] - '0';
				j++;
			}
		}
		N = j;
		
		if(N % 2 == 0){
			tmp = 10;
			idx = 0;
			if(num[0] != 0){
				i = 1;
			}else{
				i = 2;
			}
			for(; i < N; i++){
				if(num[i] - num[i - 1] < tmp
						|| (num[i] - num[i - 1] == tmp && abs(N / 2 - i - 1) < abs(N / 2 - idx - 1))){
					tmp = num[i] - num[i - 1];
					idx = i - 1;
				}
			}
			
			tmp2[0] = num[idx + 1];
			tmp1[0] = num[idx];
			i = 0;
			j = 1;
			for(; j < N / 2; i++){
				if(i == idx || i == idx + 1){
					continue;
				}
				tmp2[j] = num[i];
				j++;
			}
			i = N - 1;
			j = 1;
			for(; j < N / 2; i--){
				if(i == idx || i == idx + 1){
					continue;
				}
				tmp1[j] = num[i];
				j++;
			}
		}else{
			if(num[0] != 0){
				tmp2[0] = num[0];
				for(i = 1; i <= N / 2; i++){
					tmp2[i] = num[i];
				}
				for(i = N - 1; i > N / 2; i--){
					tmp1[N - i - 1] = num[i];
				}
			}else{
				tmp2[0] = num[1];
				tmp2[1] = num[0];
				for(i = 2; i <= N / 2; i++){
					tmp2[i] = num[i];
				}
				for(i = N - 1; i > N / 2; i--){
					tmp1[N - i - 1] = num[i];
				}
			}
		}
		
		/* テスト****************************** */
//		for(i = 0; i < (N + 1) / 2; i++){
//			printf("%d", tmp2[i]);
//		}
//		printf("\n");
//		for(i = 0; i < N / 2; i++){
//			printf("%d", tmp1[i]);
//		}
//		printf("\n");
		/* ****************************** */
		
		b = 0;
		for(i = 0; i < (N + 1) / 2; i++){
			b += tmp2[i] * power[(N + 1) / 2 - i - 1];
		}
		a = 0;
		for(i = 0; i < N / 2; i++){
			a += tmp1[i] * power[N / 2 - i - 1];
		}
//		printf("b = %d, a = %d\n", b, a);
		ans = b - a;
		
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

