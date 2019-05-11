#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>v;
ll n,b;

ll N = 1000010;
ll status[1000010];
void prime()
{
    ll i, j, sqrtN;
    sqrtN = int( sqrt((double) N ));
    for( i = 3; i <= sqrtN; i += 2 )
    {
        if( status[i] == 0 )
        {
            for( j = i * i; j <= N; j += i + i )
                status[j] = 1;
        }
    }
    v.push_back(2);
    int ck=1;
    for( i = 3; i <= N; i += 2 )
    {
        if( status[i] == 0 )
        {
            v.push_back(i);
        }
    }
}

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

ll findzero(ll n,ll p,ll m)
{
    if(p>n)
        return 1;
    ll c=0;
    for(ll i=p; n/i>=1; i*=p){
        c+=n/i;
    }
    c=c/m;
    return c;
}

int main()
{
    prime();
    scanf("%lld%lld",&n,&b);

    if(isprime(b))
        cout<<findzero(n,b,1);

    else
    {
        ll ck=0;
        for(ll i=0; v[i]*v[i]<=b; i++)
        {
            double lg=log(b)/log(v[i]);
            ll s=int(lg);
            if(s*s==b)
            {
                cout<<findzero(n,v[i],s);
                ck=1;
                break;
            }

        }
        if(ck==0)
            cout<<findzero(n,b,1);
        }

    return 0;
}

