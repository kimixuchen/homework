/**
2015-9-25
xuchen
**/
#include "stdio.h"
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first<b.first;
}

int main()
{
	int a, b;
	vector< pair<int, int> > intervals;
	while(scanf("%d%d", &a, &b)!=EOF)
	{
		if(a<b)
			intervals.push_back(make_pair(a, b));
		else
			intervals.push_back(make_pair(b, a));
	}
	sort(intervals.begin(), intervals.end(), cmp);

	int maxoverlap, cover, end, right;
	maxoverlap = 0;
	end = intervals[0].second;

	for(int i=1; i<intervals.size(); i++)
	{
		right = end>intervals[i].second ? intervals[i].second:end;
		cover = right-intervals[i].first>=0? right-intervals[i].first+1:0;
		maxoverlap = max(maxoverlap, cover);
		end = max(end, intervals[i].second);
	}

	printf("%d\n", maxoverlap);
	return 0;
}
