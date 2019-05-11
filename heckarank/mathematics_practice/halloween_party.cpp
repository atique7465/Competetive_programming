#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,c=1;
    scanf("%d",&t);
    while(c<=t)
    {
        long long int k,ans=0;
        scanf("%lld",&k);
        ans=k/2;
        ans=ans*(k-ans);
        printf("%lld\n",ans);
        c++;
    }
}
