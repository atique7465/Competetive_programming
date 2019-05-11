#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll x;
        scanf("%lld",&x);
        ll c=0,s=1;
        for(ll i=1; s<=x; i++)
        {
            s=i*i;
            if(s<=x)
            {
                x-=s;
                c++;
            }
            else
                break;
        }
        printf("%lld\n",c);
    }
    return 0;
}


