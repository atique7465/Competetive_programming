#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll>v,m;
ll mod=1000007;
ll status[1001000];
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

int main()
{
    ll n,i,j;
    scanf("%lld",&n);
    prime(n+100);
    for(i=0; v[i]<=n; i++)
    {
        ll s=0;
        ll k=v[i];
        while(k<=n)
        {
            s=s+(n/k);
            k=k*v[i];
        }
        m.push_back(s*2);
        if(v[i]==n)
            break;
    }
    ll ans=1;
    for(j=0; j<m.size(); j++)
    {
        ans=(ans*(m[j]+1))%mod;
    }
    printf("%lld",ans);
    return 0;
}
