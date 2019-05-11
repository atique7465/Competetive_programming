#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll i,n,a,q,k,s=1,min=1000000000000000,max=0,x=0;
    scanf("%lld%lld",&n,&q);
    if(n==1)
    {
        scanf("%lld",&a);
        while(q--)
        {
            scanf("%lld",&k);
            printf("%lld",a+k);
        }
    }
    else
    {
        while(n--)
        {
            scanf("%lld",&a);
            if(a>max)
                max=a;
            if(a<min)
                min=a;
            x=__gcd(x,a);
        }
        if(max==min)
            s=0;
        //cout<<x<<" "<<s<<endl;
        while(q--)
        {
            scanf("%lld",&k);
            if(s==0)
                printf("%lld",a+k);
            else
            {
                if(x==1)
                    printf("%lld",x+k);
                else
                    printf("%lld",__gcd(x,k));
            }
            if(q>0)
                cout<<endl;
        }
    }
        return 0;
    }

