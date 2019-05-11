#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll n;
        scanf("%lld",&n);

        ll c=0,tc=0;

        for(ll i=2; i*i<=n+1; i+=2)
        {
            ll k=i*i;
            if(n%k==0 && k!=n)
                c++;
        }

        for(ll i=1; i*i<=n+1; i++)
        {
            if(n%i==0)
            {
                tc+=2;
                if(i==1 || i*i==n)
                    tc-=1;
            }
        }

        if(c==0)
            printf("0\n");
        else
        {
            ll g=__gcd(c,tc);
            c=c/g;
            tc=tc/g;
            printf("%lld/%lld\n",c,tc);
        }
    }
    return 0;
}
