#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[300000];
int main()
{
    ll n,i,j;
    ll max=0,c=0;
    scanf("%lld",&n);
    scanf("%lld",&arr[1]);
    for(i=2; i<=n; i++)
    {
        scanf("%lld",&arr[i]);
        if(arr[i]<=(2*arr[i-1]))
        {
            c++;
            if(c>max)
                max=c;
        }
        else
        {
            c=0;
        }
    }
    printf("%lld",max+1);
    return 0;
}

