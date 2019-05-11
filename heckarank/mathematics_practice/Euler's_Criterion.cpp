#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll a,m;

ll mod_pow(ll a,ll b)
{
    ll ans=1;
    while(b>0)
    {
        if(b%2==1)
        {
            ans*=a;
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

int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&a,&m);
        if(a==0 || a==1)
            printf("YES\n");
        else
        {
            ll d=mod_pow(a,(m-1)/2);
            if(d==1)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
