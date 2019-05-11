#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n;
    scanf("%lld",&n);
    if(n<=2)
        printf("No");
    else
    {
        printf("Yes\n");
        printf("%lld ",n/2);
        for(ll i=2; i<=n; i+=2)
            printf("%lld ",i);

        printf("\n");
        printf("%lld ",(n-(n/2)));
         for(ll i=1; i<=n; i+=2)
            printf("%lld ",i);

    }
    return 0;
}
