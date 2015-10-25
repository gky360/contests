//poj1759.cpp
//PKU JudgeOnline
//poj1759 Garland

#include <cstdio>
#include <cmath>
#define MAX_N 1000
#define EPS 1e-10
#define INF 1e+30
using namespace std;


int N;
double A, B;
double p[MAX_N - 2], q[MAX_N - 2];	// h[i] = p[i - 1] * h[i + 1] + q[i - 1]

double add(double a, double b)
{
	return abs(a + b) < EPS * (abs(a) + abs(b)) ? 0 : a + b;
}

int main()
{
	double low, high;
	double h;
	int i;

	scanf("%d %lf", &N, &A);

	p[0] = 1.0 / 2;
	q[0] = add(A / 2, -1);
	for (i = 1; i <= N - 3; i++) {
		p[i] = 1 / add(2, -p[i - 1]);
		q[i] = p[i] * add(q[i - 1], -2);
	}

	low = 0;
	high = INF;
	while (add(high, -low) > EPS) {
		B = (high + low) / 2;
		h = B;
		for (i = N - 2; i >= 1 && h > -EPS; i--) {
			h = add(p[i - 1] * h, q[i - 1]);
		}
		if (h < -EPS) {
			low = B;
		} else {
			high = B;
		}
	}

	printf("%.2f", B);

	return 0;
}

