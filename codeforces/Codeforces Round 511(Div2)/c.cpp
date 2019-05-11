///wrong answer

#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[5000000];
ll b[10]= {2,3,5,7,11,13,17,19};
vector<ll>v;
int main()
{
    ll n;
    ll m=15000000;
    scanf("%lld",&n);
    scanf("%lld",&arr[1]);
    scanf("%lld",&arr[2]);
    ll g=__gcd(arr[1],arr[2]);

    for(ll i=3; i<=n; i++)
    {
        scanf("%lld",&arr[i]);
        g=__gcd(g,arr[i]);
    }
    ll gg=g;
    ll x=log(m)/log(g);
      //cout<<"g="<<g<<" "<<x<<endl;
      g*=g;
    for(ll i=2; i<=x; i++)
    {
        ll c=0;
        for(ll j=1; j<=n; j++)
        {
            if(arr[j]%g==0)
                c++;
        }
        v.push_back(c);
        //cout<<"c1="<<c<<endl;
        g*=g;
    }

    for(ll i=0; i<=7; i++)
    {
        if(gg%b[i]!=0){
        ll c=0;
        for(ll j=1; j<=n; j++)
        {
            if(arr[j]%b[i]==0)
                c++;
        }
        v.push_back(c);
        }
    }

    sort(v.begin(),v.end());
    ll jj;
    ll dd=0;
    for(ll i=v.size()-1; i>=0; i--)
    {
        if(v[i]!=0 && v[i]!=1)
        {
            jj=v[i];
            dd=1;
            break;
        }
    }
    if(dd==0)
        printf("-1");
    else
        printf("%lld",n-jj);
    return 0;
}
