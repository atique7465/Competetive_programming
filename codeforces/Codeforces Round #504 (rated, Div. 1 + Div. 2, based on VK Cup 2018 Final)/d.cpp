#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[300000];
ll rng[300000][3];
vector<ll>v;
int main()
{
    ll n,q,d=1;
    ll count=0;
    scanf("%lld%lld",&n,&q);
    for(ll i=1; i<=n; i++)
    {
        scanf("%lld",&arr[i]);
        if(arr[i]==0)
            count++;
        if(arr[i]!=0)
        {
            if(d==1){
             z=arr[i];
             d=0;}
            if(rng[arr[i]][1]==0)
            {
                rng[arr[i]][1]=i;
                rng[arr[i]][2]=i;
                v.push_back(arr[i]);
            }
            else
                rng[arr[i]][2]=i;
        }
    }
    ll ck=0,ck2=0;
    sort(v.begin(),v.end());
    if(v[v.size()-1]!=q && count==0)
        ck=1;
    if(v[v.size()-1]!=q && count!=0)
        ck2=1;
    for(ll i=v.size()-2; i>=0; i--)
    {
        if( (rng[v[i][1]>=rng[v[i+1][1] && rng[v[i]][1]<=rng[v[i+1]][2]) || (rng[v[i][2]>=rng[v[i+1][1] && rng[v[i]][2]<=rng[v[i+1]][2]) )
                           {
                               ck=1;
                               break;
                           }
    }
    if(ck==1)
        printf("NO");
    else
    {
        printf("YES\n");
        for(ll i=1; i<=n; i++)
        {
            if(i==1 && arr[i]==0 && ck2==0)
               printf("%lld ",q);
            else if(i==1 && arr[i]==0 && ck2==0)
                printf("%lld ",z);
            else if(arr[i]==0 && i<n)
                printf("%lld ",arr[i-1])
            else if(arr[i]!=0)
                    printf("%lld ",arr[i]);
        }
    }

    return 0;
}

