#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[100010];
vector<ll>v;
ll n,t,i,j,ck=0,g,k;
int main()
{
    scanf("%lld",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%lld",&arr[i]);
        arr[i]=arr[i]+arr[i-1];
    }
    k=arr[n];
    for(j=1; j*j<=k; j++)
    {
        if(k%j==0)
        {
            v.push_back(j);
        }
    }
    for(t=v.size()-1; t>=0; t--)
    {
        if(v[t]*v[t]==k)
        {
            continue;
        }
        else
        {
            v.push_back(k/v[t]);
        }
    }

    for(i=0; i<v.size(); i++)
    {
        if(v[i]<arr[1])
            continue;
        else
        {
            for(j=1; j*v[i]<=k; j++)
            {
                ll s=0,f=n,key=j*v[i];
                ll mid=(s+f)/2;
                while(s<=f)
                {
                    if(arr[mid]<key)
                        s=mid+1;
                    else if(arr[mid]==key){
                        ck=0;
                        break;}
                    else
                        f=mid-1;
                    mid=(s+f)/2;
                }
                if(s>f)
                    ck=1;
                if(ck==1)
                {
                    break;
                }
            }
            if(ck==0)
            {
                if(v[i]==k)
                {
                    printf("%lld",v[i]);
                }
                else
                    printf("%lld ",v[i]);
            }
        }
    }
    return 0;
}
