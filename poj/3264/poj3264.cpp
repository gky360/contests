//poj3264.cpp
//PKU Judge Online
//poj3264 Balanced Lineup

#include <cstdio>
#include <algorithm>
#define NMAX 65536	// (>50000)
#define INF 100000000
using namespace std;


int N = 0;
int Q;
int val[2][NMAX * 2 - 1];	// ƒZƒOƒƒ“ƒg–Ø, 0:min, 1:max
int init[2] = {INF, 0};
int ans;

void set(int k, int a){
	k += N - 1;
	val[0][k] = val[1][k] = a;
	while(k > 0){
		k = (k - 1) / 2;
		val[0][k] = min(val[0][k * 2 + 1], val[0][k * 2 + 2]);
		val[1][k] = max(val[1][k * 2 + 1], val[1][k * 2 + 2]);
	}
	return;
}

int query(int m, int a, int b, int k, int l, int r){
	int vl, vr;
	
	if(r <= a || b <= l){
		return init[m];
	}
	if(a <= l && r <= b){
		return val[m][k];
	}
	vl = query(m, a, b, k * 2 + 1, l, (l + r) / 2);
	vr = query(m, a, b, k * 2 + 2, (l + r) / 2, r);
	if(m == 0){
		return min(vl, vr);
	}
	return max(vl, vr);
}

int main(){
	
	int n;
	int h;
	int s, t;
	int i;
	
	scanf("%d %d", &n, &Q);
	N = 1;
	while(N < n){
		N <<= 1;
	}
	for(i = 0; i < 2; i++){
		fill(val[i], val[i] + N * 2 - 1, init[i]);
	}
	for(i = 0; i < n; i++){
		scanf("%d", &h);
		set(i, h);
	}
	
	for(i = 0; i < Q; i++){
		scanf("%d %d", &s, &t);
		ans = query(1, s - 1, t, 0, 0, N) - query(0, s - 1, t, 0, 0, N);
		printf("%d\n", ans);
	}
	
	return 0;
	
}

