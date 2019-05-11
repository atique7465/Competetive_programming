#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0)
        return a;
    else
    {
        a%=b;
        return gcd(b,a);
    }
}

ll power(ll b, ll mod)
{
    if(b < 62) return (1LL << b) % mod;
    long long ret = power(b >> 1LL, mod);
    ret = (ret * ret) % mod;
    if(b & 1LL) ret = (ret << 1LL) % mod;
    return ret;
}

ll phi(ll n)
{
    ll ret = n;
    for(ll i = 2; i * i <= n; ++i)
        if(n % i == 0)
        {
            ret -= ret / i;
            while(n % i == 0) n /= i;
        }
    if(n > 1) ret -= ret / n;
    return ret;
}

ll f(ll m)
{
    ll ph=phi(m),ret=ph;
    for(ll d=1; d*d<=ph; d++)
    {
        if(ph%d==0)
        {
            if(power(d,m)==1)
                return d;
            if(power(ph/d,m)==1)
                if(ph/d<ret)
                ret=ph/d;
        }
    }
    return ret;
}

int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll n,a;
        scanf("%lld%lld",&n,&a);
        if(a<0)
            a+=2*n+1;
        ll m=(2*n+1)/gcd(a,2*n+1);
        printf("%lld\n",2*n-f(m));
    }
    return 0;
}
