///precise one
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t,i;
    scanf("%lld",&t);
    ll low,high,mid,x,lb,ub;
    while(t--)
    {
        scanf("%lld",&x);
        low=0;
        high=1000000;
        while(low<=high)
        {
            mid=(low+high)/2;
            lb=(mid*(mid+1)*(2*mid+1))/6;
            ub=((mid+1)*(mid+2)*(2*(mid+1)+1))/6;
            if(lb<=x && ub>x)
            {
                printf("%lld\n",mid);
                break;
            }
            else if(lb<x)
            {
                low=mid+1;
            }
            else
                high=mid-1;
        }
    }
    return 0;
}
