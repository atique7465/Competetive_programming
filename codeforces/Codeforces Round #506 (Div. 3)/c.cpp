#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,x,y,a1,a2,b1,b2,ln;
    scanf("%lld",&n);
    scanf("%lld%lld",&x,&y);
    a1=a2=x;
    b1=b2=y;
    ln=y-x;
    n-=1;
    while(n--)
    {
        ll ck1=0,ck2=0;
        scanf("%lld%lld",&x,&y);
        if(a1<x)
        {
            ck1=1;
            a1=x;
        }
        if(y<b1)
        {
            ck2=1;
            b1=y;
        }

        if(n==0)
        {
            if(ck1==1 && ck2==1)
                printf("%lld",b2-a2);
            else if(ck1==1)
            {
                if(b1<b2)
                b2=b1;

                if((a1-a2)>(b2-b1))
                    printf("%lld",b1-a2);
                else
                     printf("%lld",b2-a1);
            }
            else if(ck2==1)
            {
                if(a1>a2)
                    a2=a1;
             if((a1-a2)>(b2-b1))
                    printf("%lld",b1-a2);
                else
                     printf("%lld",b2-a1);
            }
        }

        if(b1-a1<ln)
            ln=b1-a1;
        a2=x;
        b2=y;
    }
    return 0;
}

