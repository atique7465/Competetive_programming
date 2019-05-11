#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[1010][1010];
ll mod=1000000000;
void combination()//combination_value_by_pascal_table
{
    ll i,j;
    for(i=0; i<=1000; i++)
    {
        for(j=0; j<=i; j++)
        {
            if(j==0||j==i)
                arr[i][j]=1;
            else
            {
                arr[i][j]=(arr[i-1][j-1]+arr[i-1][j])%mod;
            }
        }
    }
}

int main()
{
    combination();
    int t,c=1;
    scanf("%d",&t);
    while(c<=t)
    {
        ll n,j;
        scanf("%lld",&n);
        printf("%lld",arr[n][0]);
         for(j=1; j<=n; j++){
                printf(" %lld",arr[n][j]);
        }
        printf("\n");
        c++;
    }
    return 0;
}
