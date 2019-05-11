#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll>v;
int main()
{
    ll n,m,i,j,a,b;
    ll sum1=0,sum2=0;
    scanf("%lld%lld",&n,&m);
    for(i=1; i<=n; i++){
        scanf("%lld%lld",&a,&b);
        v.push_back(a-b);
        sum1=sum1+a;
        sum2=sum2+b;
    }
    if(sum1<=m)
        printf("0");
    else if(sum2>m)
        printf("-1");
    else
    {
        ll s=sum1-m;
        sort(v.begin(),v.end());
        ll g=0,count=0;
        for(ll w=v.size()-1; w>=0; w--)
        {
            g=g+v[w];
            count++;
            if(g>=s)
                break;
        }
        printf("%lld",count);
    }
    return 0;
}
