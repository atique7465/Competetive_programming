#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,h,a,b,k,ta,i,tb,fa,fb;
    scanf("%lld%lld%lld%lld%lld",&n,&h,&a,&b,&k);
    for(i=1; i<=k; i++)
    {
        ll ans;
        scanf("%lld%lld%lld%lld",&ta,&fa,&tb,&fb);
        if(ta==tb)
            ans=abs(fb-fa);
        else if(fa>=a && fa<=b)
            ans=abs(tb-ta)+abs(fb-fa);
        else if(fa>b)
            ans=abs(fa-b)+abs(tb-ta)+abs(fb-b);
        else if(fa<a)
            ans=abs(a-fa)+abs(tb-ta)+abs(fb-a);
        printf("%lld\n",ans);
    }
    return 0;
}
