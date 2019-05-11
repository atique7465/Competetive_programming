#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll l,r;
    scanf("%lld%lld",&l,&r);
    ll n=(r-l+1)/2;
    cout<<"YES"<<endl;
    for(ll i=l; i<=r; i+=2)
        cout<<i<<" "<<i+1<<endl;
    return 0;
}

