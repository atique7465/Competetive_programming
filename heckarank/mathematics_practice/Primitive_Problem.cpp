#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll>v,m,n;
ll p;
ll status[500000];
void prime(ll N)
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

ll mod_pow(ll a,ll b)
{
    ll ans=1;
    while(b>0)
    {
        if(b%2==1)
        {
            ans=ans*a;
            if(ans>p)
                ans=ans%p;
        }
        a=a*a;
        if(a>p)
            a=a%p;
        b/=2;
    }
    return ans;
}

int main()
{
    ll i;
    scanf("%lld",&p);
    int u=int(sqrt((double)p));
    ll k=(ll)u;
    k+=10;
    prime(k);
    ll g=p-1;
    for(i=0; v[i]*v[i]<=g; i++)
    {
        if(g%v[i]==0)
        {
            while(g%v[i]==0)
                g/=v[i];
            m.push_back(v[i]);
        }
    }
    if(g>1)
        m.push_back(g);
    ll ans2=p-1;
    for(ll t=0; t<m.size(); t++)
    {
        ans2=ans2*(m[t]-1);
        ans2/=m[t];
        m[t]=(p-1)/m[t];
    }
    ll ck,ck1,ans1;
    for(i=2; i<=p-1; i++)
    {
            ck1=0;
            for(ll j=0; j<m.size(); j++)
            {
                ll d=mod_pow(i,m[j]);
                if(d==1){
                    ck1=1;
                    break;}
            }
            if(ck1==0)
            {
                ans1=i;
                break;
            }
    }
    printf("%lld %lld",ans1,ans2);
    return 0;
}

