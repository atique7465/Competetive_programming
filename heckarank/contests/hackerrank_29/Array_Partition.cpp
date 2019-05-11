#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll>v,a,m;
ll MOD=10000007;
ll q[100050];
ll N = 1050;
ll status[1050];
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

ll mod_pow(ll a, ll b)
{
    ll ans = 1;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            ans=(ans*a);
            if(ans>MOD)
                ans%=MOD;
        }
        a = (a*a);
        if(a>MOD)
            a%=MOD;
        b /= 2;
    }
    return ans;
}

int main()
{
    ll t,n,i,j,x;
    prime();
    scanf("%lld",&t);
    while(t--)
    {
        ll ans=0;
        scanf("%lld",&n);
        for(ll u=0; u<=n; u++)
        {
            scanf("%lld",&x);
            a.push_back(x);
        }

        ll c=0;
        for(i=0; i<a.size(); i++)
        {
            ll ck=0;
            for(j=0; v[j]*v[j]<=a[i]; j++)
            {
                if(a[i]%v[i]==0)
                {
                    if(q[v[i]]==1)
                    {
                        ck=1;
                        break;
                    }
                    else
                    {
                        q[v[i]]=1;
                        m.push_back(v[i]);
                        while(a[i]%v[i]==0)
                        {
                            a[i]/=v[i];
                        }
                    }
                }
            }
            if(a[i]>1)
            {
                if(q[v[i]]==1)
                    ck=1;
                else
                {
                    q[a[i]]=1;
                    m.push_back(a[i]);
                }
            }
            if(ck==0)
                c++;
        }
        ans=mod_pow(2,c);
        printf("%lld\n",ans-2);
        for(ll s=0; s<m.size(); s++)
            q[m[s]]=0;
        m.clear();
        a.clear();
    }
    return 0;
}
