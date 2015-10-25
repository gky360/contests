//poj2914_2.cpp
//PKU JudgeOnline
//poj2914 Minimum Cut

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <climits>
#define MAX_N 500
using namespace std;


int N;
int M;
int g[MAX_N][MAX_N];
int ans;

int main()
{
	int u, v;
	int sum[MAX_N];
	vector<int> idx;
	int cut;
	int a, b, c;
	int i, j, k;

	while (scanf("%d %d", &N, &M) == 2) {
		memset(g, 0, sizeof(g));
		for (i = 0; i < M; i++) {
			scanf("%d %d %d", &a, &b, &c);
			g[a][b] += c;
			g[b][a] += c;
		}
		idx.resize(N);
		for (i = 0; i < N; i++) {
			idx[i] = i;
		}
		ans = INT_MAX;

		for (k = N; k >= 2; k--) {
			//Å‘å—×Ú‡˜‚ğ‹‚ß‚é
			memset(sum, 0, sizeof(sum) * k / MAX_N);
			v = 0;
			for (j = 0; j < k; j++) {
				u = v;
				v = max_element(sum, sum + k) - sum;
				cut = sum[v];
				sum[v] = -1;
				for (i = 0; i < k; i++) {
					if (sum[i] != -1) {
						sum[i] += g[idx[v]][idx[i]];
					}
				}
			}
			ans = min(ans, cut);

			//’¸“_u, v‚ğ1‚Â‚É‚Ü‚Æ‚ß‚é
			for (i = 0; i < k; i++) {
				g[idx[u]][idx[i]] += g[idx[v]][idx[i]];
				g[idx[i]][idx[u]] += g[idx[i]][idx[v]];
			}
			idx.erase(idx.begin() + v);
		}

		printf("%d\n", ans);

	}

	return 0;
}
