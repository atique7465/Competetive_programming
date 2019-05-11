#include<bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
    int q,c=1;
    scanf("%d",&q);
    while(c<=q)
    {
        lli a,b,k,m;
        scanf("%lld%lld%lld%lld",&a,&b,&k,&m);
        lli ra=a,rb=b,v,ra2=1,rb2=1,de=0;
        while(k > 0)
        {
            if(k%2 == 1)
            {
                if(de==0)
                {
                    ra2=ra;
                    rb2=rb;
                    de=1;
                }
                else
                {
                    v=ra2;
                    ra2 = ((v*ra+m)%m-(rb2*rb+m)%m+m)%m;
                    rb2 = ((v*rb+m)%m+(rb2*ra+m)%m+m)%m;
                }
            }
            v=ra;
            ra = ((ra*ra+m)%m-(rb*rb+m)%m+m)%m;
            rb = (((2*v)%m*rb)%m+m)%m;
            k/= 2;
        }
        printf("%lld %lld\n",ra2,rb2);
        c++;
    }
    return 0;
}
