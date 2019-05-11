#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t,a,b,x;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>x;
        ll p=pow(a,b);
        ll x1=p-(p%x);
        ll x2=x1+x;
        if(p-x1<=x2-p)
            cout<<x1<<endl;
        else
            cout<<x2<<endl;
    }
    return 0;
}

