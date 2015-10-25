//poj2429.cpp
//PKU JudgeOnline
//poj2429 GCD & LCM Inverse

#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;


long long gcd(long long p, long long q);

long long GCD = 0;
long long LCM = 0;
long long ab = 0;
long long a = 0;
long long b = 0;

int main(int argc, char* argv[]){
	
	string ifn;
	string ofn;
	FILE* ifp = NULL;
	FILE* ofp = NULL;
	bool isFile = true;
	long long n = 0;
	long long i = 0;
	long long j = 0;
	
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
			fscanf(ifp, "%lld %lld", &GCD, &LCM);
		}else{
			scanf("%lld %lld", &GCD, &LCM);
		}
		if(GCD == 0){
			break;
		}
		
		ab = LCM / GCD;
		
		n = sqrt(ab);
		for(i = n; i >= 1; i--){
			if(((ab % i) == 0) && (gcd(ab / i, i) == 1)){
				printf("ab/i=%lld, i=%lld\n", ab / i, i);
				printf("ab %% i=%lld, gcd(ab/i,i)=%lld\n");
			}
		}
		
		if(ofp != NULL){
			fprintf(ofp, "%lld %lld\n", a, b);
		}
		printf("%lld %lld\n", a, b);
	}
	
	if(ifp != NULL){
		fclose(ifp);
	}
	if(ofp != NULL){
		fclose(ofp);
	}
	
	return 0;
	
}

long long gcd(long long p, long long q){
	if(q == 0){
		return p;
	}
	return gcd(q, p % q);
}

