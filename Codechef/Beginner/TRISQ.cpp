/**

Code Author : Tejas Dond & Shyam Singh
For any doubt, email me on shyam81295@gmail.com

Problem : Fit Squares in a Triangle
Type: Simple maths, AdHoc

*/

#include <stdio.h>

int main(void) {
    
    int n,x,t=0,sum;
    scanf("%d",&t);
    while(t--)
    {   x=0;
        scanf("%d",&n);
        x=n/2-1;
        sum=(x*(x+1))/2;
        
        printf("%d\n",sum);
    }
	return 0;
}
