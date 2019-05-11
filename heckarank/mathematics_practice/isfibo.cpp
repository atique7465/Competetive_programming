#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,q=1;
    scanf("%d",&t);
    while(q<=t)
    {
        long long int i,n,a=0,b=1,c;
        scanf("%lld",&n);
        if(n==0||n==1)
            printf("IsFibo\n");
        else
        {
          for(i=1; i<=60; i++)
            {
                c=a+b;
                a=b;
                b=c;
                if(c==n)
                {
                    printf("IsFibo\n");
                    break;
                }
            else if(c>n)
                {
                    printf("IsNotFibo\n");
                    break;
                }
            }
        }
        q++;
    }
    return 0;
}
