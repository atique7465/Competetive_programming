#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t,i;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&i);
        int s=int(sqrt((double)i));
        if(1LL*s*s>i)
            s-=1;
        if(s%2==0)
            printf("even\n");
        else
            printf("odd\n");
    }
    return 0;
}
