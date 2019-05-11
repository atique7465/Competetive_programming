#include<bits/stdc++.h>
using namespace std;
int mod=1234567;
int main()
{
    int t;
    scanf("%d",&t);
    int c=1;
    while(c<=t)
    {
        int n,dis,tot=1;
        scanf("%d",&n);
        for(int i=1; i<n; i++)
        {
            scanf("%d",&dis);
            tot=(tot*dis)%mod;
        }
        printf("%d\n",tot);
        c++;
    }
    return 0;
}
