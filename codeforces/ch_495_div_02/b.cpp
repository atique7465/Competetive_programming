
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[1001][3];
int main()
{
    ll n,m,i,j;
    scanf("%lld%lld",&n,&m);
    for(i=1; i<=m; i++)
        for(j=1; j<=2; j++)
          scanf("%lld",&arr[i][j]);
    for(i=1; i<=n; i++)
    {
        if(i%2!=0)
            printf("1");
        else
            printf("0");
    }
    return 0;
}
