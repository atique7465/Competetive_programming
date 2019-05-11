#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[10010];
int main()
{
    ll n,i;
    scanf("%lld",&n);
    for(i=1; i<=n; i++)
        scanf("%lld",&arr[i]);

    for(i=1; i<=n; i++)
    {
        vector<ll>v(1010);
        v[i]+=1;
        ll j=arr[i];
        ll k=j;
        while(v[j]!=1)
        {
            v[j]+=1;
            j=arr[j];
            k=j;
        }
        if(i<n)
            printf("%lld ",k);
        else
            printf("%lld",k);
    }
    return 0;
}
