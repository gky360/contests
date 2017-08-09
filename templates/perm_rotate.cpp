// perm_rotate.cpp
// permutation rotate
// ある順列から次の順列を作成

#include <cstdio>
#include <algorithm>
#define NMAX 10
using namespace std;


int num[NMAX];

int main(){

  int tmp[NMAX + 1];
  int i, j, k;

  for(i = 0; i < NMAX; i++){
    num[i] = i;
  }
  printf("> ");
  scanf("%d", &k);
  for(i = 0; i < k; i++){
    next_permutation(num, num + NMAX);
  }
  for(i = 0; i < NMAX; i++){
    printf("%d%c", num[i], i == NMAX - 1 ? '\n' : ' ');
  }

  tmp[0] = -1;
  for(j = 0; j < NMAX; j++){
    if(tmp[j] > num[NMAX - 1 - j]){
      break;
    }
    tmp[j + 1] = num[NMAX - 1 - j];
  }
  swap(num[NMAX - 1 - j], *upper_bound(tmp, tmp + j, num[NMAX - 1 - j]));
  for(i = 0; i < j; i++){
    num[NMAX - j + i] = tmp[i + 1];
  }
  for(i = 0; i < NMAX; i++){
    printf("%d%c", num[i], i == NMAX - 1 ? '\n' : ' ');
  }

  return 0;

}

