#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int arr[100010];
int ck[100010];
int cum[100010];
int used[100010];
int main()
{
    ll n,i;
    scanf("%lld",&n);
    for(i=1; i<=n; i++){
        scanf("%lld",&arr[i]);
    }
    ll c=0;
    for(i=n; i>=1; i--){
        if(ck[arr[i]]==0)
        {
            c++;
            cum[i]=c;
            ck[arr[i]]=1;
        }
        else
            cum[i]=cum[i+1];
    }
    ll count=0;
    for(i=1; i<=n; i++)
    {
        if(used[arr[i]]==0)
            {
                count+=cum[i+1];
                used[arr[i]]=1;
            }
    }
    printf("%lld",count);
    return 0;
}
