//aoj0118.cpp
//会津大学オンラインジャッジ
//aoj0118 Property Destribution

#include <cstdio>
#include <cstdlib>
#include <string>
#include <set>
#include <queue>
#include <utility>
#define WMAX 100
#define HMAX 100
using namespace std;


typedef pair<int, int> Cdn;

bool isInside(Cdn xyc);

int W = 0;
int H = 0;
char field[HMAX][WMAX + 1];
set<Cdn> unvisited;
queue<Cdn> q;
int ans = 0;

int main(int argc, char* argv[]){
	
	string ifn;
	string ofn;
	FILE* ifp = NULL;
	FILE* ofp = NULL;
	bool isFile = true;
	Cdn p;
	char c;
	int tmp = 0;
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
			tmp = fscanf(ifp, "%d %d", &H, &W);
		}else{
			tmp = scanf("%d %d", &H, &W);
		}
		if(H == 0){
			break;
		}
		
		for(j = 0; j < H; j++){
			if(ifp != NULL){
				tmp = fscanf(ifp, "%s", field[j]);
			}else{
				tmp = scanf("%s", field[j]);
			}
		}
		
		for(j = 0; j < H; j++){
			for(i = 0; i < W; i++){
				unvisited.insert(make_pair(j, i));
			}
		}
		
		ans = 0;
		while(!unvisited.empty()){
			p = *(unvisited.begin());
			q.push(p);
			c = field[p.first][p.second];
			while(!q.empty()){
				p = q.front();
				q.pop();
				
				if(!isInside(p) || field[p.first][p.second] != c || unvisited.erase(p) == 0){
					continue;
				}
				
				q.push(make_pair(p.first - 1, p.second));
				q.push(make_pair(p.first, p.second + 1));
				q.push(make_pair(p.first + 1, p.second));
				q.push(make_pair(p.first, p.second - 1));
			}
			ans++;
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

bool isInside(Cdn xyc){
	return (0 <= xyc.second) && (xyc.second < W) && (0 <= xyc.first) && (xyc.first < H);
}


