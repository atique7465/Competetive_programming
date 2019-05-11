#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    int c=1;
    while(c<=t)
    {
        int n;
        scanf("%d",&n);
        int ans=0;
        ans=((n-1)*(n))/2;
        printf("%d\n",ans);
        c++;
    }
    return 0;
}
