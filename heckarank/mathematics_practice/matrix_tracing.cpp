#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll mod=1000000007;
ll f(ll n)
{
    if(n<2)
        return 1;
    else
        return (n*f(n-1))%mod;
}

ll mi(ll a)
{
    ll ans=1;
    ll b=mod-2;
    while(b)
    {
        if(b%2!=0)
        {
            ans=(ans*a);
            if(ans>mod)
                ans=ans%mod;
        }
        a=(a*a);
        if(a>mod)
            a=a%mod;
        b/=2;
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll m,n;
        scanf("%lld%lld",&m,&n);
        printf("%lld\n",(f(m+n-2)*mi((f(m-1)*f(n-1))%mod))%mod);
    }
    return 0;
}

