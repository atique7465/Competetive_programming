#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    else
    {
        a%=b;
        return gcd(b,a);
    }
}

int main()
{
    ll a,b,x,y;
    scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
    ll g=gcd(x,y);

    ll x1=x/g;
    ll y1=y/g;


    x1=a/x1;

    y1=b/y1;

    ll ans;

    if(x1>y1)
        ans=y1;
    else
        ans=x1;

    printf("%lld",ans);
    return 0;
}
