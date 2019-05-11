#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,a,b,x;

vector<ll> etf;
vector<bool > P;
void ETF(ll n){
    etf.resize(n+1);
    P.resize(n+1,0);
    for(ll i=1;i<=n;i++)
        etf[i]=i;
    for(ll i=2;i<=n;i++){
        if(!P[i]){
            etf[i]-=(etf[i]/i);
            int j=2*i;
            while(j<=n){
                etf[j]-=(etf[j]/i);
                P[j]=1;
                j+=i;
            }
        }
    }
}

ll Pow_mod(ll a,ll b,ll m)
{
    ll ans=1;
    while(b>0)
    {
        if(b%2==1)
        {
            ans=((ans%m)*(a%m))%m;
        }
        a=((a%m)*(a%m))%m;
        b/=2;
    }
    return ans;
}

int main()
{
    ETF(1000000);
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&a,&b,&x);
        if(b>=0)
            printf("%lld\n",Pow_mod(a,b,x));
        else
        {
            printf("%lld\n",Pow_mod(Pow_mod(a,etf[x]-1,x),-b,x));
        }
    }
    return 0;
}
