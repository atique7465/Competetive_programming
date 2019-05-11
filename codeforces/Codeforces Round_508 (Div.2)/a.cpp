#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[30];
int main()
{
    string c="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    ll n,k;
    scanf("%lld%lld",&n,&k);
    string s;
    cin>>s;
    for(ll i=0; i<k; i++)
    {
        for(ll j=0; j<n; j++)
        {
            if(s[j]==c[i])
                arr[i+1]++;
        }
    }
    ll min=1000000000;
    for(ll i=1; i<=k; i++)
    {
        if(arr[i]<min)
            min=arr[i];
    }

    printf("%lld",min*k);
    return 0;
}


