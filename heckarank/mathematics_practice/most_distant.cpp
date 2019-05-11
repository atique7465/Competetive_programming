#include<bits/stdc++.h>
#define ll long long
#define scan1(a) scanf("%lld",&a)
#define scan2(a,b) scanf("%lld%lld",&a,&b)
#define print(a) printf("%lld\n",a)
using namespace std;
int main()
{
    ll n,c=1,a,b,maxx=-1000000000,minx=1000000000,maxy=-1000000000,miny=1000000000;
    scan1(n);
    while(c<=n)
    {
        scan2(a,b);
            maxx=max(maxx,a);
            minx=min(minx,a);
            maxy=max(maxy,b);
            miny=min(miny,b);
        c++;
    }

    double mx=max(abs(maxx-minx),abs(maxy-miny));
    double q1=sqrt(minx*minx + maxy*maxy);
    double q2=sqrt(maxx*maxx + maxy*maxy);
    double q3=sqrt(minx*minx + miny*miny);
    double q4=sqrt(maxx*maxx + miny*miny);
    if(n>2)
    printf("%.07f",max(mx,max(q1,max(q2,max(q3,q4)))));
    else
        printf("%.07f",mx);
    return 0;
}
