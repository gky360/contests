//poj3669.cpp
//PKU JudgeOnline
//poj3669 Meteor Shower

#include <cstdio>
#include <cstdlib>
#include <string>
#include <queue>
#include <utility>
#define WMAX 300
#define HMAX 300
#define INF 100000000
using namespace std;


typedef pair<int, int> Cdn;

int M = 0;
int place[WMAX + 3][HMAX + 3];
//int d[WMAX + 3][HMAX + 3];
int vx[5] = {0, 1, 0, -1, 0};
int vy[5] = {1, 0, -1, 0, 0};
queue<Cdn> q;
int ans = -1;

int main(int argc, char* argv[]){
	
	string ifn;
	string ofn;
	FILE* ifp = NULL;
	FILE* ofp = NULL;
	bool isFile = true;
	int meteor[3];
	int px = 0;
	int py = 0;
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
	
	for(j = 0; j < HMAX + 3; j++){
		for(i = 0; i < WMAX + 3; i++){
			place[i][j] = INF;
//			d[i][j] = INF;
		}
	}
	for(i = 0; i < WMAX + 3; i++){
		place[i][0] = 0;
		place[i][HMAX + 2] = 0;
//		d[i][0] =0;
//		d[i][HMAX + 2] = 0;
	}
	for(j = 0; j < HMAX + 3; j++){
		place[0][j] = 0;
		place[WMAX + 2][j] = 0;
//		d[0][j] = 0;
//		d[WMAX + 2][j] = 0;
	}
	
	if(ifp != NULL){
		fscanf(ifp, "%d", &M);
	}else{
		scanf("%d", &M);
	}
	
	for(i = 0; i < M; i++){
		if(ifp != NULL){
			fscanf(ifp, "%d %d %d", &meteor[0], &meteor[1], &meteor[2]);
		}else{
			scanf("%d %d %d", &meteor[0], &meteor[1], &meteor[2]);
		}
		meteor[0]++;
		meteor[1]++;
		for(k = 0; k < 5; k++){
			if(meteor[2] < place[meteor[0] + vx[k]][meteor[1] + vy[k]]){
				place[meteor[0] + vx[k]][meteor[1] + vy[k]] = meteor[2];
			}
		}
	}
	
	if(place[1][1] == INF){
		ans = 0;
	}else if(place[1][1] > 0){
		q.push(make_pair(1, 1));
//		d[1][1] = 0;
		place[1][1] = 0;
	}
	while(!q.empty()){
		px = q.front().first;
		py = q.front().second;
		q.pop();
		
/*		for(j = 0; j < 10; j++){
			for(i = 0; i < 10; i++){
				if(place[i][j] == INF){
					k = 0;
				}else{
					k = place[i][j];
				}
				printf("%d ", k);
			}
			printf("\n");
		}
		printf("\n");
*/
		
		for(k = 0; k < 4; k++){
			if(place[px + vx[k]][py + vy[k]] == INF){
//				ans = d[px][py] + 1;
				ans = place[px][py] + 1;
				break;
			}else if(place[px + vx[k]][py + vy[k]] > place[px][py] + 1){
				place[px + vx[k]][py + vy[k]] = place[px][py] + 1;
				q.push(make_pair(px + vx[k], py + vy[k]));
			}
		}
		if(ans >= 0){
			break;
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

