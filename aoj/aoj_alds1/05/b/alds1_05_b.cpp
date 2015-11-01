// Algorithms and Data Structures I
// 05 - Recursion / Divide and Conquer
// B - Merge Sort

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_N 500000
#define INF 1000000001


int N;
int nums[MAX_N];
int cnt;

void merge(int *arr, int l, int r) {
  int tmp_l[MAX_N / 2 + 2], tmp_r[MAX_N / 2 + 2];
  int nl = (r + l) / 2 - l;
  int nr = r - (r + l) / 2;

  memcpy(tmp_l, arr + l, sizeof(int) * nl);
  memcpy(tmp_r, arr + (r + l) / 2, sizeof(int) * nr);
  tmp_l[nl] = INF;
  tmp_r[nr] = INF;
  int il = 0;
  int ir = 0;
  for (int i = l; i < r; i++) {
    if (tmp_l[il] < tmp_r[ir]) {
      arr[i] = tmp_l[il];
      il++;
    } else {
      arr[i] = tmp_r[ir];
      ir++;
    }
    cnt++;
  }
  return;
}

void merge_sort(int *arr, int l, int r) {
  if (r - l <= 1) {
    return;
  }
  merge_sort(arr, l, (r + l) / 2);
  merge_sort(arr, (r + l) / 2, r);
  merge(arr, l, r);
  return;
}

int main() {

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &nums[i]);
  }

  merge_sort(nums, 0, N);

  for (int i = 0; i < N; i++) {
    printf("%d%c", nums[i], (i == N - 1) ? '\n' : ' ');
  }
  printf("%d\n", cnt);

  return 0;

}


