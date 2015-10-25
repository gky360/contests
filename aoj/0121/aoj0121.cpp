//aoj0121.cpp
//会津大学オンラインジャッジ
//aoj0121 Seven Puzzle

#include <cstdio>
#include <cstdlib>
#include <string>
#include <cctype>
#include <queue>
#include <set>
#include <utility>
using namespace std;

typedef pair<int, int> Cdn;


class Puzzle{
public:
	int card[6][4];
	Cdn blank;
	int n;
private:
public:
	Puzzle();
	void init();
	void assign(int x, int y, int a);
private:
};

Puzzle::Puzzle(){
	init();
	return;
}

void Puzzle::init(){
	int i = 0;
	int j = 0;
	
	for(j = 0; j < 4; j++){
		for(i = 0; i < 6; i++){
			card[i][j] = 0;
		}
	}
	blank.first = 0;
	blank.second = 0;
	n = 0;
	return;
}

void Puzzle::assign(int x, int y, int a){
	card[x][y] = a;
	if(a == 0){
		blank.first = x;
		blank.second = y;
	}
	return;
}

bool operator <(Puzzle a, Puzzle b){
	int i = 0;
	int j = 0;
	
	for(j = 1; j <= 2; j++){
		for(i = 1; i <= 4; i++){
			if(a.card[i][j] < b.card[i][j]){
				return true;
			}else if(a.card[i][j] > b.card[i][j]){
				return false;
			}
		}
	}
	return false;
}

bool operator >(Puzzle a, Puzzle b){
	int i = 0;
	int j = 0;
	
	for(j = 1; j <= 2; j++){
		for(i = 1; i <= 4; i++){
			if(a.card[i][j] > b.card[i][j]){
				return true;
			}else if(a.card[i][j] < b.card[i][j]){
				return false;
			}
		}
	}
	return false;
}

bool operator ==(Puzzle a, Puzzle b){
	int i = 0;
	int j = 0;
	
	for(j = 1; j <= 2; j++){
		for(i = 1; i <= 4; i++){
			if(a.card[i][j] != b.card[i][j]){
				return false;
			}
		}
	}
	return true;
}


queue<Puzzle> q;
set<Puzzle> s;
Puzzle finish;
int vx[4] = {0, 1, 0, -1};
int vy[4] = {-1, 0, 1, 0};
int ans = 0;

int main(int argc, char* argv[]){
	
	string ifn;
	string ofn;
	FILE* ifp = NULL;
	FILE* ofp = NULL;
	bool isFile = true;
	Puzzle p;
	Puzzle tmpP;
	int tmp = 0;
	int x = 0;
	int y = 0;
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
	
	for(i = 0; i < 8; i++){
		finish.assign(i % 4 + 1, i / 4 + 1, i);
	}
	
	while(true){
		for(i = 0; i < 8; i++){
			if(ifp != NULL){
				fscanf(ifp, "%d", &tmp);
			}else{
				scanf("%d", &tmp);
			}
			p.assign(i % 4 + 1, i / 4 + 1, tmp);
			printf("%d ", tmp);
		}
		
		while(!q.empty()){
			q.pop();
		}
		s.clear();
		q.push(p);
		s.insert(p);
		while(!q.empty()){
			p = q.front();
			q.pop();
			
			if(ofp != NULL){
				for(int j = 1; j <= 2; j++){
					for(i = 1; i <= 4; i++){
						fprintf(ofp, "%d ", p.card[i][j]);
					}
					fprintf(ofp, "\n");
				}
				fprintf(ofp, "\n");
			}else{
				for(int j = 1; j <= 2; j++){
					for(i = 1; i <= 4; i++){
						printf("%d ", p.card[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			if(p == finish){
				ans = p.n;
				break;
			}
			
			x = p.blank.first;
			y = p.blank.second;
			for(i = 0; i < 4; i++){
				tmpP = p;
				tmpP.card[x][y] = tmpP.card[x + vx[i]][y + vy[i]];
				tmpP.card[x + vx[i]][y + vy[i]] = 0;
				tmpP.blank.first = x + vx[i];
				tmpP.blank.second = y + vy[i];
				tmpP.n++;
				if(s.find(tmpP) == s.end()){
					q.push(tmpP);
					s.insert(tmpP);
				}
			}
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

