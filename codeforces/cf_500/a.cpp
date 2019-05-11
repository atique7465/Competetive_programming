#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr1[100];
ll arr2[100];
int main()
{
    ll n,i,j;
    scanf("%lld",&n);
    ll sum1=0;
    for(i=1; i<=n; i++)
    {
        scanf("%lld",&arr1[i]);
        sum1=sum1+arr1[i];
    }
    ll sum2=0;
    for(j=1; j<=n; j++)
    {
        scanf("%lld",&arr2[j]);
        sum2=sum2+arr2[j];
    }
    if(sum2<=sum1)
        printf("Yes");
    else
        printf("No");
    return 0;
}
