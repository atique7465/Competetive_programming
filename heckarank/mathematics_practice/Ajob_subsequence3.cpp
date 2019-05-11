#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mod;
ll arr[1000010];

void factmod()
{
    arr[0]=1;
    for(ll i=1; i<=mod; i++)
    {
        arr[i]=((arr[i-1]%mod)*(i%mod))%mod;
    }
}

ll pow_mod(ll a,ll b)
{
    ll ans=1;
    while(b>0)
    {
        if(b%2==1)
        {
            ans=ans*a;
            if(ans>mod)
                ans%=mod;
        }
        a=a*a;
        if(a>mod)
            a%=mod;
        b/=2;
    }
    return ans;
}


ll ncr(ll n,ll r)
{
    if(r>n)
    {
        return 0;
    }
    if(n==r || r==0)
    {
        return 1;
    }
    ll up=arr[n];
    ll down=arr[r];
    down=((down%mod)*(arr[n-r]%mod))%mod;
    down=pow_mod(down,mod-2);
    up=((up%mod)*(down%mod))%mod;

    return up;
}

ll solve(ll n,ll r)
{
    factmod();
    ll res=1;
    while(n>0)
    {
        res=((res%mod)*(ncr(n%mod,r%mod)%mod))%mod;
        n/=mod;
        r/=mod;
    }
    return res;
}

int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll n,k,p;
        scanf("%lld%lld%lld",&n,&k,&p);
        mod=p;
        printf("%lld\n",solve(n+1,n-k));
    }
    return 0;
}
