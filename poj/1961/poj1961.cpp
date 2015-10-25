//PKU JUdgeOnline
//poj1961 Period

#include<cstdio>
#define NMAX 1000000
using namespace std;


int n;
char s[NMAX + 2];
int next[NMAX + 1];
int testcase;
int ans;

int main(){

    int i, j;

    for(testcase = 1; ; testcase++){
	scanf("%d", &n);
	if(n == 0){
	    break;
	}
	scanf("%s", s);
	printf("Test case #%d\n", testcase);

	i = 1;
	j = 0;
	next[0] = next[1] = 0;
	while(i < n){
	    if(s[i] == s[j]){
		if((i + 1) % (i - j) == 0){
		    printf("%d %d\n", i + 1, (i + 1) / (i - j));
		}
		i++;
		j++;
		next[i] = j;
	    }else if(j == 0){
		i++;
		next[i] = j;
	    }else{
		j = next[j];
	    }
	}

	printf("\n");
    }

    return 0;
    
}
