//aoj0005.cpp
//AIZU ONLINE JUDGE
//aoj0005 GCD and LCM

#include <cstdio>
using namespace std;


int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int A, B;
int ans_gcd, ans_lcm;

int main()
{
	while(scanf("%d %d", &A, &B) == 2){
		ans_gcd = gcd(A, B);
		ans_lcm = A / ans_gcd * B;
		printf("%d %d\n", ans_gcd, ans_lcm);
	}

	return 0;
}

