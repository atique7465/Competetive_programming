#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define scan1(a) scanf("%lld",&a)
#define scan2(a,b,x,y) scanf("%lld%lld%lld%lld",&a,&b,&x,&y)

ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    a%=b;
    return gcd(b,a);
}

int main()
{
    ll n,c=1,a,b,x,y;
    scan1(n);
    while(c<=n)
    {
        scan2(a,b,x,y);
        if(gcd(a,b)==gcd(x,y))
            printf("YES\n");
        else
            printf("NO\n");
        c++;
    }
    return 0;
}
