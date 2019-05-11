#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,k,a[100010],x=0,q=4;
    scanf("%lld%lld",&n,&k);
    for(ll i=1; i<=n; i++)
    {
        scanf("%lld",&a[i]);
        x=__gcd(a[i],x);
    }

    ll ans = 0;
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            ans = max(ans, k - k % i);
            ans = max(ans, k - k % (x / i));
        }
    }
    ans = max(ans, k - k % x);
    printf("%d\n", ans);
    return 0;
}
