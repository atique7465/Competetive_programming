#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>u1,u2;
ll i,n,m,k,a;
int main()
{
    scanf("%lld%lld%lld",&n,&m,&k);
    for(i=1; i<=n; i++)
    {
        scanf("%lld",&a);
        u1.push_back(a);
        u2.push_back(a);
    }

    sort(u1.begin(),u1.end());

    ll s=0;

    ll e=n-(m*k);
    for(i=u1.size()-1; i>=e; i--)
        s+=u1[i];

    cout<<s<<endl;

    ll cnt=0,pr=0;
    for(i=0; i<u2.size()-1; i++)
    {
        if(u2[i]>=u1[e]){
            cnt++;
        }
        if(cnt==m && pr<k-1)
        {
            pr++;
            cout<<i+1<<" ";
            cnt=0;
        }
    }
    return 0;
}
