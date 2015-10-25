//poj1002.cpp
//poj
//ñ‚ëË1002 487-3279

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <vector>
#define NMAX 1000000
using namespace std;


bool tf = false;

class Node{
public:
	Node* edge[10];
	int n;
private:
public:
	Node();
	~Node();
	void show();
private:
};

Node::Node(){
	int i = 0;
	
	n = 0;
	for(i = 0; i < 10; i++){
		edge[i] = NULL;
	}
	return;
}

Node::~Node(){
	int i = 0;
	
	for(i = 0; i < 10; i++){
		if(edge[i] != NULL){
			delete edge[i];
		}
	}
	return;
}

void Node::show(){
	static vector<int> number;
	int i = 0;
	
	if(n >= 2){
		for(i = 0; i < 3; i++){
			printf("%d", number[i]);
		}
		printf("-");
		for(i = 3; i < 7; i++){
			printf("%d", number[i]);
		}
		printf(" %d\n", n);
		tf = true;
		return;
	}
	
	for(i = 0; i < 10; i++){
		if(edge[i] != NULL){
			number.push_back(i);
			edge[i]->show();
			number.pop_back();
		}
	}
	return;
}


int N = 0;
char str[NMAX][100];
int code[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 0, 7, 7, 8, 8, 8, 9, 9, 9, 0};
Node root;

int main(){
	
	Node* p = &root;
	int tmp = 0;
	int i = 0;
	int j = 0;
	
	/* ì¸óÕ */
	tmp = scanf("%d", &N);
	
	for(i = 0; i < N; i++){
		tmp = scanf("%s", str[i]);
	}
	
	/* ââéZ */
	for(i = 0; i < N; i++){
		p = &root;
		
		for(j = 0; str[i][j] != '\0'; j++){
			if(!isalnum(str[i][j])){
				continue;
			}
			
			if('0' <= str[i][j] && str[i][j] <= '9'){
				tmp = str[i][j] - '0';
			}else{
				tmp = code[str[i][j] - 'A'];
			}
			
			if(p->edge[tmp] == NULL){
				p->edge[tmp] = new Node();
			}
			p = p->edge[tmp];
		}
		
		p->n++;
	}
	
	/* èoóÕ */
	root.show();
	if(!tf){
		printf("No duplicates.\n");
	}
	
	return 0;
}


