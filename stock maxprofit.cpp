/**
 * 2015-11-16 20:41:36
 * xuchen
**/
/**
 * How to maximize profit of stock with k trades
**/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <stdlib.h>
using namespace std;

const int N = 17;
const int MIN = -1e6;
const int price[N] = 
	{100, 113, 110, 85, 105,
	 102, 86, 63, 81, 101,
	 94, 106, 101, 79, 94,
	 90, 97};
int changes[N];
int f[N][N];

//get maxprofit from i to j with 1 trade
int getMaxprofit(int i, int j)
{
	int ans = MIN;
	int sum = ans;
	for(int k=i+1; k<=j; k++)
	{
		if(sum<0)
			sum = changes[k];
		else
			sum += changes[k];
		ans = max(ans, sum);	
	}	
	return ans;
}

//maximize profit with k trades
void solve(int k)
{
	int _max = MIN;
	for(int i=2; i<=k; i++)
	{
		for(int j=i; j<N; j++)
		{
			for(int d = i; d<j; d++)
			{
				_max = max(_max, f[d][i-1] + getMaxprofit(d, j));	
			}
			f[j][i] = _max;
		}
	}
}

int main()
{

	changes[0] = 0;
	for(int i=1; i<N; i++)
	{
		changes[i] = price[i]-price[i-1];
	}

	int ans;	
	for(int k=1; k<=4; k++)
	{
		for(int i=0; i<N; i++)
			f[i][1] = getMaxprofit(0, i);

		solve(k);
		printf("k= %d max= %d\n", k, f[N-1][k]);
	}
	return 0;
}
