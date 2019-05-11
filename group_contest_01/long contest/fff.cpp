#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100009
ll arr[sz];
int main()
{
    int n,x,a=0,i;
    ll sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%I64d",&arr[i]);
    sort(arr,arr+n);


    for(i=0;i<n;i++)
    {
        if(arr[i]<sum)
        {
            a++;
            continue;
        }
        sum+=arr[i];
    }

    printf("%d\n",n-a);
}
