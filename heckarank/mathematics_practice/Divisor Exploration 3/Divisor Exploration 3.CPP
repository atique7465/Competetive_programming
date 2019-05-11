#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll m=1e9+7;
vector<ll>v;
ll N = 8000;
ll status[8000];
ll arr[2010][2010];
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

void ncr()//combination_value_by_pascal_table
{
    ll i,j;
    for(i=0; i<=2000; i++)
    {
        for(j=0; j<=i; j++)
        {
            if(j==0||j==i)
                arr[i][j]=1;
            else
            {
                arr[i][j]=(arr[i-1][j-1]+arr[i-1][j])%m;
            }
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

ll f(ll p, ll a, ll d)
{
    ll ans;
    if(d==1)
        return ans=pow_mod(p,a);
    else
    {
        ans=(((p%m)*( f(p,a,d-1)%m))%m - (arr(a+d-2,d-2)%m) +m)%m;
        ll inv=pow_mod(p-1,m-2);
        ans= ((ans%m)*(inv%m))%m;
    }
    return ans;
}

int main()
{
    prime();
    ncr();
    ll q;
    scanf("%lld",&q);
    while(q--)
    {
        ll n,a,d,res=1;
        scanf("%lld%lld%lld",&m,&a,&d);
        for(ll i=0; i<m; i++)
        {
            ll p=v[i];
            res=( res%m )*( f(p,a+i+1,d) %m )%m;
        }
        printf("%lld\n",res);
    }
    return 0;
}
