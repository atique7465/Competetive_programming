#include<bits/stdc++.h>
#define ll long long int
using namespace std;
long long int mod=100000;
int main()
{
    int t,c=1;
    scanf("%d",&t);
    while(c<=t)
    {
        ll i,n,ans=1;
        scanf("%lld",&n);
        for(i=1; i<=n; i++){
        ans = (ans*2)%mod;
        }
        printf("%lld\n",ans-1);
        c++;
    }
    return 0;
}
