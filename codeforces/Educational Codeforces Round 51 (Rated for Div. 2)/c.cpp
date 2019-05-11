#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[300];
vector<ll>v,m;

int main()
{
    ll n;
    scanf("%lld",&n);
    for(ll i=1; i<=n; i++)
        scanf("%lld",&arr[i]);

    for(ll i=1; i<=n; i++)
    {
        ll ck=0,c=0;
        for(ll j=1; j<=n; j++)
        {
            if(j!=i && arr[j]==arr[i])
            {
                ck=1;
                c++;
            }
            if(c>=2)
                break;
        }
        if(ck==0)
        {
            v.push_back(i);
        }
        if(c>=2)
        {
            m.push_back(i);
        }
    }

    if(v.size()%2!=0 && m.size()==0)
        printf("NO");
    else
    {
        printf("YES\n");
        char ch[n];
        for(ll j=0; j<n; j++)
            ch[j]='A';
        for(ll i=0; i<v.size()/2; i++)
        {
            ch[v[i]-1]='B';
        }
        if(v.size()%2!=0 && m.size()!=0)
            ch[m[0]-1]='B';
        for(ll j=0; j<n; j++)
            cout<<ch[j];
    }
    return 0;
}


