#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll mod_pow(ll a,ll b, ll m)
{
    ll ans=1;
    while(b>0)
    {
        if(b%2==1)
        {
            ans*=a;
            if(ans>m)
                ans%=m;
        }
        a*=a;
        if(a>m)
            a%=m;
        b/=2;
    }
    return ans;
}

int main()
{
    ll t,n;
    ll m=1000000000+7;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ll x=(mod_pow(2,n,m-1)-n)%(m-1);
        x=(x+m-1)%(m-1);
        printf("%lld\n",mod_pow(2,x,m));
    }
    return 0;
}
