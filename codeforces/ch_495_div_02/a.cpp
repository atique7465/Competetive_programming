#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[101];
int main()
{
    ll n,d,i,count=0,m=1000000000;
    scanf("%lld%lld",&n,&d);
    for(i=1; i<=n; i++)
    {
        scanf("%lld",&arr[i]);
        if(i==1)
        {
            count++;
        }
        if(i>1)
        {
            if((arr[i]-arr[i-1])>(2*d))
            {
                count+=2;
            }

            else if((arr[i]-arr[i-1])==(2*d))
            {
                count++;
            }
        }
        if(i==n)
        {
            count++;
        }
    }
    printf("%lld",count);
    return 0;
}
