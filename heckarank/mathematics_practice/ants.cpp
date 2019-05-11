#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[200];
int main()
{
    ll n;
    scanf("%lld",&n);
    ll i,j;
    for(i=0; i<n; i++)
    {
        scanf("%lld",&arr[i]);
    }
    ll ans=(n-(n/2))*(n/2)*2*100000;
    sort(arr,arr+n);
    ll c=0;
    for(i=0;i<n; i++)
    {
        if(arr[i]+1==arr[i+1])
            c++;
        else
        {
            ans+=(c+1)/2;
            c=0;
        }
    }
    printf("%lld",ans*2LL);
    return 0;
}
