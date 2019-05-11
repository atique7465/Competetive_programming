#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,num,ans;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&num);
            int h=num,m=num,s;
            while(h>0)
            {
                h/=10;
                s=m-(h*10);
                ans=ans+s;
                m=h;
            }
        }
        if(ans%3==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
