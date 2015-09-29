/**
2015-9-29
xuchen
**/
#include "stdio.h"
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int maxoverlap;
vector< pair<int, int> > intervals;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first<b.first;
}

int solve(int l, int r)
{
	if(l>=r)
		return 0;
	int mid = (l+r)/2;
	int lMax, rMax;
	int mMax = 0;
	int cover;
	int end;
	int lEndMax = 0;
	pair<int, int> x = intervals[mid];
	
	for(int i=l; i<=mid-1; i++)
		lEndMax = max(lEndMax, intervals[i].second);
	
	if(lEndMax>x.first && lEndMax<=x.second)
	{
		mMax = lEndMax-x.first;
		lEndMax = x.second;
	}
	else if(lEndMax>x.second)
	{
		mMax = x.second-x.first;
	}
	else
		lEndMax = x.second;
	
	for(int i=mid+1; i<=r; i++)
	{
		if(intervals[i].first>lEndMax)
			break;
		end = min(intervals[i].second, lEndMax);
		cover = end-intervals[i].first;
		mMax = max(mMax, cover);
	}
	
	lMax = solve(l, mid-1);
	rMax = solve(mid+1, r);
	lMax = max(lMax, rMax);
	
	return max(mMax, lMax);
	
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
	sort(intervals.begin(), intervals.end(), cmp);
	
	size = intervals.size();
	maxoverlap = solve(0, size-1);
	printf("%d\n", maxoverlap);

	return 0;
}


