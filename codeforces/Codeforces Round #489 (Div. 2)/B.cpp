#include<bits/stdc++.h>
using namespace std;

int main()
{
    int l,r,x,y,a,b,count=0;
    scanf("%d%d%d%d",&l,&r,&x,&y);
    l = ceil(1.00000 * l / x);
    r = floor(1.0000 * r / x);
    if(y%x!=0)
        printf("0");
    else
    {
        y=y/x;
        for(int i=1; i<=sqrt(y); i++)
        {
            if(y%i==0)
            {
                int d=y/i;
                if(__gcd(i,d)==1)
                {
                    if((i>=l&&i<=r)&&(d>=l&&d<=r))
                    {
                        count++;
                        if(i!=d)
                            count++;
                    }

                }
            }
        }
        printf("%d",count);
    }
    return 0;
}

