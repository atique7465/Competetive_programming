#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll m=1e9+7;
vector<ll>v;
ll inv[1299720];
ll N = 1299720;
ll status[1299720];
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

ll pow_mod(ll a,ll b)
{
    ll ans=1;
    while(b>0)
    {
        if(b%2==1)
        {
            ans=ans*a;
            if(ans>m)
                ans%=m;
        }
        a=a*a;
        if(a>m)
            a%=m;
        b/=2;
    }
    return ans;
}

void pre()
{
    for(ll i=0; i<v.size(); i++)
    {
        inv[v[i]-1]= pow_mod(v[i]-1,m-2);
    }
}

int main()
{
    prime();
    pre();
    ll q;
    scanf("%lld",&q);
    while(q--)
    {
        ll n,a;
        scanf("%lld%lld",&n,&a);
        ll ans=1;
        for(ll i=0; i<n; i++)
        {
            ll sod=( ( pow_mod(v[i],a+i+1+1) -1+m)%m * inv[v[i]-1] )%m;
            ll g=( (v[i] * sod)%m -(a+i+1 + 1) +m )%m ;
            ans=((ans%m) * g)%m;
            ans=((ans%m) * inv[v[i]-1])%m;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
