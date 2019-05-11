#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n,q,x,y;
    scanf("%lld%lld",&n,&q);
    while(q--)
    {
        scanf("%lld%lld",&x,&y);
        ll p=((x-1)*n)+y;
        if(n%2==0)
        {
            if((x+y)%2==0)
            {
                printf("%lld\n",p-(p/2));
            }
            else
            {
                ll ans=((1LL*n*n)/2)+((p-1)/2)+1;
                printf("%lld\n",ans);
            }
        }

        else
        {
            if((x+y)%2==0)
            {
                printf("%lld\n",((p-1)/2)+1);
            }
            else
            {
                ll ans=((1LL*n*n)/2)+(p/2);
                if((1LL*n*n)%2!=0)
                    ans=ans+1;
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
