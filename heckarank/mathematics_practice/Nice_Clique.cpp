#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[300];
ll N = 50000000;
ll status[50000000];
vector<ll>v,dd;

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

bool Miller(ll p)
{
    if(p<2)
    {
        return false;
    }
    if(p!=2 && p%2==0)
    {
        return false;
    }
    ll s=p-1;
    while(s%2==0)
    {
        s/=2;
    }
    for(ll i=0; i<sz; i++)
    {
        ll a=witness[i],temp=s;
        ll mod=modulo(a,temp,p);
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
    for(ll i=0; i<sz; i++)
        if(n==witness[i])
            return true;
    for(ll i=0; i<sz; i++)
        if(n%witness[i]==0)
            return false;
    return Miller(n);
}

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
    for( i = 3; i <= N; i += 2 )
    {
        if( status[i] == 0 )
        {
            v.push_back(i);
        }
    }
}

int main()
{
    prime();
    ll n;
    scanf("%lld",&n);

    for(ll i=1; i<=n; i++)
        scanf("%lld",&arr[i]);

    ll s1=0,s2=0,s3=0,s4=0;

    for(ll a=1; a<=n; a++)
    {
        ll x=arr[a];
        ll q=0,sum=1;
        if(isprime(x))
        {
            sum+=x;
            q++;;
        }
        else
        {
            for(ll i=0; v[i]*v[i]<=x; i++)
            {
                if(x%v[i]==0)
                {
                    q++;
                    ll r=v[i];
                    while(x%v[i]==0)
                    {
                        x/=v[i];
                        r*=v[i];
                    }
                    sum*=(r-1)/(v[i]-1);
                }
            }
            if(x>1)
            {
                q++;
                sum*=((x*x)-1)/(x-1);
            }
        }
        if(q%2==0 && sum%2==0)
            s1++;
        if(q%2==0 && sum%2==1)
            s2++;
        if(q%2==1 && sum%2==0)
            s3++;
        if(q%2==1 && sum%2==1)
            s4++;
    }

    dd.push_back(s1+s2);
    dd.push_back(s1+s3);
    dd.push_back(s2+s4);
    dd.push_back(s3+s4);

    sort(dd.begin(),dd.end());

    printf("%lld",dd[dd.size()-1]);
    return 0;
}
