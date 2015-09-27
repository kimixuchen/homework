/**
2015-9-25
xuchen
**/
#include "stdio.h"
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int maxoverlap;
vector< pair<int, int> > intervals;

void solve(int l, int r)
{
	if(l>=r)
		return ;
	pair<int, int> x = intervals[l];
	int pos = l;
	int cover;
	pair<int, int> tmp;
	int right;
	for(int i=l+1; i<=r; i++)
	{
		if(intervals[i].first<x.first)
		{
			if(intervals[i].second>=x.first)
			{
				right = min(intervals[i].second, x.second);
				cover = right - x.first;
				maxoverlap = max(maxoverlap, cover);
			}
			pos++;
			tmp = intervals[pos];
			intervals[pos] = intervals[i];
			intervals[i] = tmp;
		}
		else
		{
			if(x.second>=intervals[i].first)
			{
				right = min(x.second, intervals[i].second);
				cover = right - intervals[i].first;
				maxoverlap = max(maxoverlap, cover);
			}
		}
	}
	tmp = intervals[pos];
	intervals[pos] = x;
	intervals[l] = tmp;

	solve(l, pos-1);
	solve(pos+1, r);	
}

int main()
{
	int a, b, size;
	while(scanf("%d%d", &a, &b) && !(a==0 && b==0))
	{
		if(a<b)
			intervals.push_back(make_pair(a, b));
		else
			intervals.push_back(make_pair(b, a));
	}
	size = intervals.size();
	solve(0, size-1);
	printf("%d\n", maxoverlap);

	return 0;
}
