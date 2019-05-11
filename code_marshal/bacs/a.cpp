#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,c=1,a,b,i;
    int arr[200];
    scanf("%d",&t);
    while(c<=t)
    {
        int ck=0;
        scanf("%d",&n);
        scanf("%d",&arr[1]);
            for(i=2; i<=n; i++)
            {
                scanf("%d",&arr[i]);
                if(arr[i]-arr[i-1]==1)
                    ck=1;
            }
        if(ck==1)
            printf("Case %d: Yes\n",c);
        else
            printf("Case %d: No\n",c);
        c++;
    }
    return 0;
}
