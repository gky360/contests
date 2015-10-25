//poj1017.cpp
//PKU JudgeOnline
//poj1017 Packets

#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;


int p[6 + 1] = {0, 0, 0, 0, 0, 0, 0};
int table[8] = {0, 19, 15, 11, 9, 5, 3, 1};
int sum = 0;
int ans = 0;

int main(int argc, char* argv[]){
	
	string ifn;
	string ofn;
	FILE* ifp = NULL;
	FILE* ofp = NULL;
	bool isFile = true;
	int num = 0;
	int tmp = 0;
	int remain = 0;
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
		sum = 0;
		if(ifp != NULL){
			for(i = 1; i <= 6; i++){
				fscanf(ifp, "%d", &p[i]);
				sum += p[i];
			}
		}else{
			for(i = 1; i <= 6; i++){
				scanf("%d", &p[i]);
				sum += p[i];
			}
		}
		if(sum == 0){
			break;
		}
		
		ans = 0;
		for(i = 6; i >= 1; i--){
/*			for(j = 1; j <= 6; j++){
				printf("%d ", p[j]);
			}
			printf("\n");
*/			if(p[i] == 0){
				continue;
			}
			
			tmp = (6 / i) * (6 / i) * (6 / i);
			num = (p[i] + tmp - 1) / tmp;
			remain = 6 * 6 * 6 * num - p[i] * i * i * i;
//			printf("tmp = %d, ", tmp);
//			printf("num = %d, ", num);
//			printf("remain = %d\n", remain);
			ans += num;
			for(j = min(6 - i, i - 1); j >= 1; j--){
				if(i == 3 && j == 2){
					num = min(p[j], table[p[i] % tmp]);
				}else{
					num = min(p[j], remain / (j * j * j));
//					printf("%d\n", remain / (j * j * j));
				}
				remain -= j * j * j * num;
				p[j] -= num;
//				printf("\tj = %d: num = %d, remain = %d\n", j, num, remain);
			}
			p[i] = 0;
		}
		
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

