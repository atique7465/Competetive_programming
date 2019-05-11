#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>v;

int main()
{
    ll n;
    scanf("%lld",&n);
    ll a;
    for(ll i=1; i<=n; i++)
    {
        scanf("%lld",&a);
        v.push_back(a);
    }

    sort(v.begin(),v.end());
    ll sum=0;
    for(ll i=1; i<v.size(); i++)
    {
        sum=sum+v[i]-v[i-1]-1;
    }

    printf("%lld",sum);
    return 0;
}
