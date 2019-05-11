#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n,k;
    scanf("%lld%lld",&n,&k);
    if(n>=k)
        printf("1");
    else
    {
        if(k%n==0)
            printf("%lld",k/n);
        else
        {
            ll ans=(k/n)+1;
            printf("%lld",ans);
        }
    }
    return 0;
}
