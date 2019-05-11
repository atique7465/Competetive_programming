#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,c,ans=0,ck1=1,ck2=1;
    scanf("%d%d",&n,&m);
    int x1,y1;
    x1=n;
    y1=m;
    if(n==1&&m==1)
        printf("%d",1);
    else if(n==1||m==1)
    {
        if(n==1)
        {
            if(m%2!=0)
                printf("%d",m/2+1);
            else
                printf("%d",m/2);
        }
        if(m==1)
        {
            if(n%2!=0)
                printf("%d",n/2+1);
            else
                printf("%d",n/2);
        }
    }

    else
    {
        if(m>1)
        {
            if(n>1)
            {
                n/=2;
            }
            m/=2;
            ans=ans+(n*m);
        }

        if(x1%2!=0)
        {
            if(y1%2==0)
                ans=ans+(y1/2);
            else
            {
                ck1=0;
                ans=ans+(y1/2)+1;
            }
        }
        if(y1%2!=0)
        {
            if(x1%2==0)
                ans=ans+(x1/2);
            else
            {
                ck2=0;
                ans=ans+(x1/2)+1;
            }
        }
        if(ck1==0&&ck2==0)
        {
            ans=ans-1;
        }
        printf("%d",ans);
    }
    return 0;
}
