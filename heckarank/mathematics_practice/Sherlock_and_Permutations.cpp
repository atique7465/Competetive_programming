#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[2010][2010];
ll mod=1000000007;
ll combination(ll n,ll r)//combination by backtracking
{
    ll ans;
    if(r==0||r==n)
        return 1;
    if(r==1)
        return n;
    if(arr[n][r]!=0)
        return arr[n][r];

    arr[n][r]=(combination(n-1,r-1)+combination(n-1,r))%mod;
    return arr[n][r];
}
int main()
{
    int t,c=1;
    scanf("%d",&t);
    while(c<=t)
    {
        ll m,n;
        scanf("%lld%lld",&n,&m);
        ll ans=combination(m+n-1,n);
        printf("%lld\n",ans);
        c++;
    }
    return 0;
}
