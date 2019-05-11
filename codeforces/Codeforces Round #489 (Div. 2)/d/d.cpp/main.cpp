#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005],ng[200005];
ll n,i,j,k;

bool overflow(ll a,ll b)
{
    if(a<=((long long)2e18)/b)
    return false;
    return true;
}

int main()
{
    scanf("%lld%lld",&n,&k);

    for(i=1; i<=n; i++)
        scanf("%lld",&a[i]);

    ng[n+1]=n+1;
    for(i=n; i>=1; i--)
    {
        if(a[i]==1)
            ng[i]=ng[i+1];
        else
            ng[i]=i;
    }

    ll ans=0;
    for(i=1; i<=n; i++)
    {
        ll sum=0,mul=1,rp=i;

        while(1){
        sum+=a[rp];
        mul*=a[rp];

        if(mul==sum*k)
            ans++;

        rp++;
        if(a[rp]==1)
        {
            ll ones=ng[rp]-rp;
            ll need=mul-sum*k;

            if(need>0 && need%k==0 && ones*k>=need)
                ans++;

            sum+=ones;
            rp=ng[rp];
        }
        if(rp>n)
            break;
        if(overflow(a[rp],mul))
            break;
        }
    }
    printf("%lld",ans);
    return 0;
}
