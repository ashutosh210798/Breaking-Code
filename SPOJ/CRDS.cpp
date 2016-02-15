/*

Code Author : Shyam Singh
For any doubt, email me on shyam81295@gmail.com

Problem : Cards
Type: Simple maths, AdHoc

*/

#include<bits/stdc++.h>
#define MOD_mini 1000007
using namespace std;

long dp[1000005];

int main()
{
	int T,k;
	long N,i;
	dp[1] = 2;
	for(i=2;i<=1000000;i++)
	{
		dp[i] = (dp[i-1] + (i-1) + 2*i)%MOD_mini;
	}

	scanf("%d",&T);
	for(k=0;k<T;k++)
	{
		scanf("%ld",&N);
		printf("%ld\n",dp[N]);
	}
	return 0;
}
