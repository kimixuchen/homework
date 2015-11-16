/**
*produce random intervals
**/
#include "stdio.h"
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
	int a, b;
	const int M = 64282323;
	int counts = 5000;
	for(int i=0; i<counts; i++)
	{
		a = random(M);
		b = random(M);
		cout<<a<<" "<<b<<endl;
	}
	
	
	return 0;
}
