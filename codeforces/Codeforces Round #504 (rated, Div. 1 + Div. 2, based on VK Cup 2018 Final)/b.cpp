#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n,k;
    scanf("%lld%lld",&n,&k);
    if((k-n)>=n)
        printf("0");
    else
    {
        if(k>n)
            printf("%lld",(n-(k-n)+1)/2);
        else
            printf("%lld",(k-1)/2);
    }
    return 0;
}
