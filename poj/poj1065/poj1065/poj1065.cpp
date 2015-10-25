//poj1065.cpp
//PKU JudgeOnline
//poj1065 Wooden Sticks

#include <cstdio>
#include <set>
#include <utility>
#include <algorithm>
#define NMAX 5000
using namespace std;


int N;
pair<int, int> stick[NMAX];	// first:l, second:w
multiset<int> ends;	// ‘‰Á•”•ª—ñ‚Ì‚»‚ê‚¼‚ê‚ÌÅŒã”ö‚Ì’l

int main()
{
	int t;
	set<int>::iterator iter;
	int i;

	for(scanf("%d", &t); t > 0; t--){
		scanf("%d", &N);
		for(i = 0; i < N; i++){
			scanf("%d %d", &stick[i].first, &stick[i].second);
		}
		ends.clear();
		ends.insert(0);

		sort(stick, stick + N);

		for(i = 0; i < N; i++){
			iter = ends.upper_bound(stick[i].second);
			iter--;
			if(iter != ends.begin()){
				ends.erase(iter);
			}
			ends.insert(stick[i].second);
		}

		printf("%d\n", ends.size() - 1);
	}

	return 0;

}

