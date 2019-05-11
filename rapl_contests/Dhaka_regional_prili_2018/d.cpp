#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> witness;
ll sz=4;
ll mulmod(ll a, ll b,ll c)
{
    ll x = 0,y=a%c;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x = (x+y)%c;
        }
        y = (y*2LL)%c;
        b /= 2;
    }
    return x%c;
}
ll modulo(ll a, ll b, ll c)
{
    ll x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=mulmod(x,y,c);
        }
        y = mulmod(y,y,c);
        b /= 2;
    }
    return x%c;
}

bool Miller(long long p)
{
    if(p<2)
    {
        return false;
    }
    if(p!=2 && p%2==0)
    {
        return false;
    }
    long long s=p-1;
    while(s%2==0)
    {
        s/=2;
    }
    for(int i=0; i<sz; i++)
    {
        long long a=witness[i],temp=s;
        long long mod=modulo(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1)
        {
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0)
        {
            return false;
        }
    }
    return true;
}

bool isprime(ll n)
{
    witness.push_back(2);
    witness.push_back(13);
    witness.push_back(23);
    witness.push_back(1662803);
    for(int i=0; i<sz; i++)
        if(n==witness[i])
            return true;
    for(int i=0; i<sz; i++)
        if(n%witness[i]==0)
            return false;
    return Miller(n);
}

bool check(ll n)
{
    ll s,ck=0;
    while(n>0)
    {
        s=n%10;
        if(s!=2 && s!=3 && s!=5 && s!=7)
        {
            ck=1;
            break;
        }
        n/=10;
    }
    if(ck==0)
        return true;
    else
        return false;
}

int main()
{
    ll t,e=1;
    scanf("%lld",&t);
    while(e<=t)
    {
        ll n,x;
        scanf("%lld",&n);
        if(n%2==0)
            n=n-1;
        ll count=0;
        for(ll i=n; i>=0; i-=2)
        {
            if(isprime(i))
            {
                if(check(i))
                {
                    cout<<i<<" ";
                    count++;
                }
            }
        }
        cout<<endl<<count<<endl;
       // printf("Case %lld: %lld\n",e,x);
        e++;
    }
    return 0;
}

