//aoj2170.cpp
//会津大学オンラインジャッジ
//aoj2170 Marked Ancestor

#include <cstdio>
#include <cstdlib>
#include <string>
#define NMAX 100000
#define QMAX 100000
using namespace std;


int root(int a);

int N = 0;
int Q = 0;
int r[NMAX];
int p[NMAX];
int que[QMAX][2];
int ans = 0;

int main(int argc, char* argv[]){
	
	string ifn;
	string ofn;
	FILE* ifp = NULL;
	FILE* ofp = NULL;
	bool isFile = true;
	char c = 0;
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
	
	while(true){
		if(ifp != NULL){
			fscanf(ifp, "%d %d", &N, &Q);
		}else{
			scanf("%d %d", &N, &Q);
		}
		if(N == 0){
			break;
		}
		p[0] = 0;
		r[0] = 0;
		for(i = 1; i < N; i++){
			if(ifp != NULL){
				fscanf(ifp, "%d", &p[i]);
			}else{
				scanf("%d", &p[i]);
			}
			p[i]--;
			r[i] = p[i];
		}
		for(i = 0; i < Q; i++){
			if(ifp != NULL){
				fscanf(ifp, "\n%c %d", &c, &que[i][1]);
			}else{
				scanf("\n%c %d", &c, &que[i][1]);
			}
			que[i][1]--;
			if(c == 'M'){
				que[i][0] = 0;
			}else if(c == 'Q'){
				que[i][0] = 1;
			}
		}
		
		for(i = 0; i < Q; i++){
			if(que[i][0] == 0){	/* Mのとき */
				r[que[i][1]] = que[i][1];
			}
		}
		
		ans = 0;
		for(i = Q - 1; i >= 0; i--){
			if(que[i][0] == 0){	/* Mのとき */
				r[que[i][1]] = /*root(*/p[que[i][1]]/*)*/;
			}else{	/* Qのとき */
				ans += root(p[que[i][1]]) + 1;
			}
		}
		
		if(ifp != NULL){
			fprintf(ifp, "%d\n", ans);
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

int root(int a){
	if(r[a] != a){
		r[a] = root(r[a]);
	}
	return r[a];
}

