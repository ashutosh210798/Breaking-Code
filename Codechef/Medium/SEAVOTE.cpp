/**
Code Author : Shyam Singh
For any doubt, email me on shyam81295@gmail.com

Problem : Sereja and Votes 
Type: AdHoc
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long T,N,i,j,k,a,sum,counter;
    long matrix[1005];
    bool flag;
    scanf("%ld",&T);
    for(k=0;k<T;k++)
    {
        scanf("%ld",&N);
        sum = 0;
        counter = 0;
        flag = false;
        for(i=0;i<N;i++)
        {
            scanf("%ld",&a);
            sum+=a;
            if(a>0)     counter++;
	    if(a>100)   flag = true;
        }
        if((!flag)&&(sum>=100)&&((sum-counter)<100)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
