#include<bits/stdc++.h>
#define ll long long int
ll arr[110][100];
int main()
{
    ll t,i,j,n;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
                scanf("%lld",&arr[i][j]);
        }
        ll ck=0;
        for(i=1; i<=n-1; i++)
        {
            for(j=1; j<=n-1; j++)
            {
                if(arr[n][n]==arr[n][n-1] || arr[n][n]==arr[n-1][n])
                {
                    ck=1;
                    break;
                }
                if(arr[i][j]==arr[i][j+1] || arr[i][j]==arr[i+1][j])
                {
                    ck=1;
                    break;
                }
            }
        }
        if(ck==0)
            printf("Yes\n");
        else
            printf("No\n");
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
                arr[i][j]=0;
        }
    }
    return 0;
}

