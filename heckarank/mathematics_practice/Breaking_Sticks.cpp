#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll>v,m;
ll N = 1000010;
ll arr[200];
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

void pf(ll a)
{
    for(ll i=0; v[i]*v[i]<=a; i++)
    {
        if(a%v[i]==0)
        {
            while(a%v[i]==0)
            {
                a/=v[i];
                m.push_back(v[i]);
            }
        }
    }
    if(a>1)
    {
        m.push_back(a);
    }
}

int main()
{
    prime();
    ll n,ans=0,i,j;
    scanf("%lld",&n);
    for(i=1; i<=n; i++)
        scanf("%lld",&arr[i]);
    for(i=1; i<=n; i++)
    {
        if(arr[i]==1)
        {
            ans=ans+1;
        }
        else
        {
            pf(arr[i]);
            ll res=1;
            for(j=m.size()-1; j>0; j--)
            {
                res=res*m[j];
                ans=ans+res;
            }
            ans=ans+arr[i]+1;
            m.clear();
        }
    }
    printf("%lld",ans);
    return 0;
}
