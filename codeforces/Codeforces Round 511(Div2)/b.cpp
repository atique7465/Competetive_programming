#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n;
    scanf("%lld",&n);
    ll max=0;
    for(ll i=1; i<=n; i++)
    {
        ll a,b;
        cin>>a>>b;
        if(a+b>max)
            max=a+b;
    }

    cout<<max;

    return 0;
}

