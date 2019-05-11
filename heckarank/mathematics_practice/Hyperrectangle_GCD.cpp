#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mod=1e9+7;
ll arr[1010];

vector<ll>etf;
vector<bool>P;
void ETF(int n){
    etf.resize(n+1);
    P.resize(n+1,0);
    for(int i=1;i<=n;i++)
        etf[i]=i;
    for(int i=2;i<=n;i++){
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

int main()
{
    ll t,k;
    scanf("%lld",&t);
    while(t--)
    {
        ll min=10000000;
        scanf("%lld",&k);
        for(ll i=1; i<=k; i++)
        {
            scanf("%lld",&arr[i]);
            if(arr[i]<min)
            {
                min=arr[i];
            }
        }
        ETF(min);
        ll sum=0;
        for(ll i=1; i<=min; i++)
        {
            ll s=1;
            for(ll j=1; j<=k; j++)
            {
                ll h=arr[j]/i;
                s=((s%mod)*(h%mod))%mod;
            }
            sum+=((s%mod)*(etf[i]%mod))%mod;
            sum%=mod;
        }
        printf("%lld\n",sum);
        etf.clear();
        P.clear();
    }
    return 0;
}
