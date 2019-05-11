#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,c=1;
    scanf("%d",&t);
    while(c<=t)
    {
        long long int r,b,g,y,n;
        scanf("%lld %lld %lld %lld %lld",&r,&b,&g,&y,&n);
        long long int ans;
        ans=4*(n-1)+1;
        printf("%lld\n",ans);
        c++;
    }
    return 0;
}


