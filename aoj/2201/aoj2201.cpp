//aoj2201.cpp
//AIZU ONLINE JUDGE
//aoj2201 Immortal Jewels

#include <cstdio>
#include <cmath>
#include <algorithm>
#define N_MAX 50
#define EPS 1e-10
using namespace std;


int N;
int x[N_MAX], y[N_MAX];
int r[N_MAX];
int m[N_MAX];
int ans;

class con_doub{	// convenient double
	public:
		double val;
		con_doub();
		con_doub(double d);
};

con_doub::con_doub(){
	val = 0;
	return;
}

con_doub::con_doub(double d){
	val = d;
	return;
}

con_doub operator+(con_doub d1, con_doub d2){
	d1.val += d2.val;
	if(abs(d1.val) < EPS){
		d1.val = 0;
	}
	return d1;
}

con_doub operator-(con_doub d1, con_doub d2){
	d1.val -= d2.val;
	if(abs(d1.val) < EPS){
		d1.val = 0;
	}
	return d1;
}

con_doub operator-(con_doub d){
	d.val *= -1;
	return d;
}

con_doub operator*(con_doub d1, con_doub d2){
	d1.val *= d2.val;
	return d1;
}

con_doub operator/(con_doub d1, con_doub d2){
	d1.val /= d2.val;
	return d1;
}

bool operator==(con_doub d1, con_doub d2){
	d1 = d1 - d2;
	return d1.val == 0;
}

bool operator<=(con_doub d1, con_doub d2){
	d1 = d1 - d2;
	return d1.val <= 0;
}

bool operator<(con_doub d1, con_doub d2){
	d1 = d1 - d2;
	return d1.val < 0;
}

void common_tangent(con_doub x0, con_doub y0, con_doub r0, con_doub x1, con_doub y1, con_doub r1){
	con_doub a[2][2], b[2][2], c[2][2], p, q, s, t, u, d;	// ‹‚ß‚éÚü:y=ax+b, ax-cy+b=0(c:0or1)
	con_doub pm0[2], pm1[2];
	int cnt;
	int i, j, k, l;
	
	pm0[0].val = pm1[0].val = 1;
	pm0[1].val = pm1[1].val = -1;
	for(i = 0; i <= 1; i++){
		if(pm0[i] * r0 - r1 == con_doub(0)){
			if(x1 - x0 == con_doub(0)){	// c‚Ìê‡
				for(j = 0; j <= 1; j++){
					a[i][j] = con_doub(1);
					b[i][j] = -x0 - pm1[j] * r0;
					c[i][j] = con_doub(0);
				}
			}else{
				for(j = 0; j <= 1; j++){
					a[i][j] = (y1 - y0) / (x1 - x0);
					b[i][j] = pm1[j] * r0 * con_doub(sqrt(a[i][j].val * a[i][j].val + 1)) - a[i][j] * x0 + y0;
					c[i][j] = con_doub(1);
				}
			}
		}else{
			p = (-pm0[i] * r0 * x1 + r1 * x0) / (pm0[i] * r0 - r1);
			q = (pm0[i] * r0 * y1 - r1 * y0) / (pm0[i] * r0 - r1);
			s = (p + x0) * (p + x1) - pm0[i] * r0 * r1;
			t = (p + x0) * (q - y1) + (p + x1) * (q - y0);
			u = (q - y0) * (q - y1) - pm0[i] * r0 * r1;
			if(s == con_doub(0)){	// 1ŽŸŽ®‚É‚È‚é=•Ð•ûc‚Ìê‡
				a[i][0] = -u / t;	// ©H
				b[i][0] = p * a[i][0] + q;
				c[i][0] = 1;
				a[i][1] = con_doub(1);
				for(k = 0; k <= 1; k++){
					for(l = 0; l <= 1; l++){
						if(x0 + pm0[k] == x1 + pm1[l]){
							b[i][1] = -x0 - pm0[k];
						}
					}
				}
				c[i][1] = con_doub(0);
			}else{
				d = t * t - con_doub(4) * s * u;
				if(d < con_doub(0)){	// ”»•ÊŽ®d<0
					for(j = 0; j <= 1; j++){
						a[i][j] = b[i][j] = c[i][j] = 0;
					}
				}else{
					for(j = 0; j <= 1; j++){
						a[i][j] = (-t + pm1[j] * con_doub(sqrt(d.val))) / (con_doub(2) * s);
						b[i][j] = p * a[i][j] + q;
						c[i][j] = con_doub(1);
					}
				}
			}
		}
	}
	
	for(i = 0; i <= 1; i++){
		for(j = 0; j <= 1; j++){
			if(a[i][j] == con_doub(0) && b[i][j] == con_doub(0) && c[i][j] == con_doub(0)){
				continue;
			}
			cnt = 0;
			for(k = 0; k < N; k++){
				d.val = abs((a[i][j] * con_doub(x[k]) - c[i][j] * con_doub(y[k]) + b[i][j]).val) / sqrt(a[i][j].val * a[i][j].val + 1);	// d:distance
				if(con_doub(r[k]) <= d && d <= con_doub(r[k] + m[k])){
					cnt++;
				}
			}
			ans = max(ans, cnt);
		}
	}
	
	return;
}

int main(){
	
	int i, j, k, l;
	
	while(true){
		scanf("%d", &N);
		for(i = 0; i < N; i++){
			scanf("%d %d %d %d", &x[i], &y[i], &r[i], &m[i]);
		}
		if(N == 0){
			break;
		}else if(N == 1){
			printf("1\n");
			continue;
		}
		
		ans = 0;
		for(i = 0; i < N; i++){
			for(j = i + 1; j < N; j++){
				for(k = 0; k <= 1; k++){
					for(l = 0; l <= 1; l++){
						common_tangent(x[i], y[i], r[i] + k * m[i], x[j], y[j], r[j] + l * m[j]);
					}
				}
			}
		}
		
		printf("%d\n", ans);
		
	}
	
	return 0;
	
}

