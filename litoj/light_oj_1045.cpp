#include<bits/stdc++.h>
using namespace std;
double cumsum[1000005];
int main()
{
    for(int i=1; i<=1000002; i++)
    {
        cumsum[i]=cumsum[i-1]+log(i);

    }
    int tc,cas=1;
    scanf("%d",&tc);
    while(cas<=tc)
    {
        int n,b;
        scanf("%d",&n);
        scanf("%d",&b);
        if(n==0 || n==1)
        {
            printf("Case %d: 1\n",cas);
            cas++;
        }
        else
        {
            double ans=cumsum[n];
            ans/=log(b);
            ans=floor(ans);
            ans+=1.0;
            printf("Case %d: %.0lf\n",cas,ans);
            cas++;
        }
    }
    return 0;
}
