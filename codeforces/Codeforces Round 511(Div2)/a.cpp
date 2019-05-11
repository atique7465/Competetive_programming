#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n;
    scanf("%lld",&n);
    ll a=1,b=1,c;
    c=n-2;
    if(c%3==0)
        b=b+1;
    c=n-(a+b);
    cout<<a<<" "<<b<<" "<<c;
    return 0;
}
