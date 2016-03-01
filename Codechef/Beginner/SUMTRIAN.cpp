    /*
    
    Code Author : Shyam Singh
    For any doubt, email me on shyam81295@gmail.com
    
    Problem : Sums in a Triangle
    Type : simple DP
    
    */
    
    #include <bits/stdc++.h>
    using namespace std;
    
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
            int i,j,n;
            cin>>n;
            int a[n][n],b[n+1][n+1];
            for(i=0;i<n;++i)
            {
                for(j=0;j<=i;++j)
                    scanf("%d",&a[i][j]);
            }
            memset(b,0,sizeof(b));
            for(i=n-1;i+1;--i)
            {
                for(j=0;j<=i;++j)
                    b[i][j]=a[i][j]+max(b[i+1][j],b[i+1][j+1]);
            }
            printf("%d\n",b[0][0]);
        }
        return 0;
    }
