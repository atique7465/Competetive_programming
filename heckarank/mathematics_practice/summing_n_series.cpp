#include<bits/stdc++.h>
using namespace std;
unsigned long long int mod=1000000007;
int main()
{
    int t,c=1;
    scanf("%d",&t);
    while(c<=t)
    {
        unsigned long long int n,ans=0;
        scanf("%llu",&n);
        n%=mod;
        ans=(n*n)%mod;
        printf("%llu\n",ans);
        c++;
    }
    return 0;
}

