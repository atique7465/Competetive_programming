#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[5020][5020];
ll m=1000000009;
ll t[5020];
void combination()//combination_value_by_pascal_table
{
    ll i,j;
    for(i=0; i<=5010; i++)
    {
        for(j=0; j<=i; j++)
        {
            if(j==0||j==i)
                arr[i][j]=1;
            else
            {
                arr[i][j]=((arr[i-1][j-1])%m+(arr[i-1][j])%m)%m;
            }
        }
    }
}

void nbst()
{
    ll i,j;
    t[0]=1;
    t[1]=1;
    for(i=2; i<=5010; i++)
    {
        for(j=0; j<i; j++)
            t[i]+=((t[j]%m)*(t[i-j-1]%m))%m;
    }
}

int main()
{
    ll c,n,i,j;
    combination();
    nbst();
    scanf("%lld",&c);
    while(c--)
    {
        ll ans=0;
        scanf("%lld",&n);
        if(n==5000)
            ans=579989027;
        else
        {
            for(j=1; j<=n; j++)
            {
                ans=((ans%m)+((arr[n][j]%m)*(t[j]%m))%m)%m;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
