#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll q;
    scanf("%lld",&q);
    while(q--)
    {
        ll n;
        scanf("%lld",&n);
        ll a,b,d=0;
        while(n--)
        {
            scanf("%lld%lld",&a,&b);
            b+=d;
            if(a>=b)
                d=0;
            else if(a<b)
                d=b-a;
            if(n==0 && d>0)
                printf("1\n");
            else if(n==0 && d==0)
                printf("0\n");
        }
    }
    return 0;
}
