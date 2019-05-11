#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll>etf,w;
vector<bool>p;
ll n;

ll find()
{
    ll i,sum=0,num;
    num=1000000000000LL;
    i=0;
    while(sum<=num)
    {
        sum+=i;
        i++;
    }
    return i;
}

void weird_function()
{
    w.resize(n,0);
    for(ll i=1; i<n; i++)
    {
        if(i%2)
        {
            w[i]=etf[i];
            w[i]=w[i]*etf[(i+1)/2];
        }
        else
        {
            w[i]=etf[i/2];
            w[i]=w[i]*etf[i+1];
        }
    }
    for(ll i=1; i<n; i++)
        w[i]+=w[i-1];
}

void ETF()
{
    n=find();
    etf.resize(n+1);
    p.resize(n+1,0);
    for(int i=1; i<=n; i++)
        etf[i]=i;
    for(int i=2; i<=n; i++)
    {
        if(!p[i])
        {
            etf[i]-=(etf[i]/i);
            int j=2*i;
            while(j<=n)
            {
                etf[j]-=(etf[j]/i);
                p[j]=1;
                j+=i;
            }
        }
    }
    weird_function();
}

ll test_cases(ll L, ll R)
{
    ll l,r;
    l=(sqrt(1+8*L)-1)/2;
    r=(sqrt(1+8*R)-1)/2;
    if((l*(l+1))==2*L)
        return (w[r]-w[l-1]);
    else
        return (w[r]-w[l]);

}

int main()
{
    ll t;
    ETF();
    scanf("%lld",&t);
    ll maxx=1000000000000LL;
    assert(t<=100000);
    while(t--)
    {
        ll L,R;
        scanf("%lld%lld",&L,&R);
        assert(1<=L && L<=maxx && L<=R && R<=maxx && R>=1);
        printf("%lld\n",test_cases(L,R));
    }
    return 0;
}
