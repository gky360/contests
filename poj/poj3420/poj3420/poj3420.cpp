//poj3420.cpp
//PKU JudgeOnline
//poj3420 Quad Tiling

#include <cstdio>
#include <cstring>
#include <climits>
#define SIZE 5
using namespace std;
typedef long long LL;


class SquareMatrix
{
public:
	LL a[SIZE][SIZE];
	void init();
	void init(LL tmp_a[SIZE][SIZE]);
};

void SquareMatrix::init()
{
	int i;
	
	memset(a, 0, sizeof(a));
	for (i = 0; i < SIZE; i++) {
		a[i][i] = 1;
	}
	return;
}

void SquareMatrix::init(LL tmp_a[SIZE][SIZE])
{
	int i, j;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			a[i][j] = tmp_a[i][j];
		}
	}
	return;
}

int N;
int M;
SquareMatrix A;
int ans;

SquareMatrix operator *(SquareMatrix m1, SquareMatrix m2)
{
	SquareMatrix m;
	int i, j, k;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			m.a[i][j] = 0;
			for (k = 0; k < SIZE; k++) {
				m.a[i][j] += m1.a[i][k] * m2.a[k][j];
			}
			m.a[i][j] %= M;
		}
	}

	return m;
}

SquareMatrix pow(SquareMatrix m, int n)
{
	SquareMatrix res;

	res.init();
	for (; n > 0; n = n >> 1) {
		if (n & 1) {
			res = res * m;
		}
		m = m * m;
	}
	return res;
}

int main()
{
	LL tmp_a[SIZE][SIZE] = {{1, 4, 1, 0, 1},
							{1, 0, 0, 0, 0},
							{0, 2, 1, 0, 0},
							{0, 1, 0, 0, 1},
							{0, 0, 0, 1, 0}};
	
	while (scanf("%d %d", &N, &M) && N != 0) {
		if (N == 1) {
			ans = 1;
		} else {
			A.init(tmp_a);
			A = pow(A, N - 2);
			ans = (A.a[0][0] * 5 + A.a[0][1] * 1 + A.a[0][2] * 2 + A.a[0][3] * 1 + A.a[0][4] * 0) % M;
		}
		printf("%d\n", ans);
	}

	return 0;
}

