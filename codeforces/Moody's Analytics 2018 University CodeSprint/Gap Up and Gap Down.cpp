#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll l[100010];
ll h[100010];
ll c[100010];
int main()
{
    ll n;
    scanf("%lld",&n);
    ll i;
    for(i=1; i<=n; i++)
    {
        scanf("%lld",&l[i]);
    }
    for(i=1; i<=n; i++)
    {
        scanf("%lld",&h[i]);
    }
    for(i=1; i<=n; i++)
    {
        scanf("%lld",&c[i]);
    }

    ll gu=0,gd=0;
    for(i=2; i<=n; i++)
    {
        if(l[i]>c[i-1])
            gu++;
        if(h[i]<c[i-1])
            gd++;
    }

    printf("%lld %lld",gu,gd);
    return 0;
}
