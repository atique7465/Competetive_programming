#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll prefix[1000005];
ll suffix[1000005];
ll a[1000005];
int main()
{
    int n;
    cin>>n;

    if(n==1)
    {
        ll x;
        cin>>x;
        cout<<x+1<<endl;
        return 0;
    }
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=n; i++)
    {
        prefix[i]=__gcd(a[i],prefix[i-1]);
    }
    for(int i=n; i>=1; i--)
    {
        suffix[i]=__gcd(suffix[i+1],a[i]);
    }
    for(int i=1; i<=n; i++)
    {
        ll cur=__gcd(prefix[i-1],suffix[i+1]);
        if(a[i]%cur!=0)
        {
            cout<<cur;
            return 0;
        }
    }

}

