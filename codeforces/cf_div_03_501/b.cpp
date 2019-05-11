#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll>v;
int main()
{
    ll n;
    cin>>n;
    string s,t;
    char c,ck=0;
    cin>>s>>t;
    ll i,j;
    for(i=0; i<n; i++)
    {
        if(t[i]!=s[i])
        {
            ck=1;
            break;
        }
    }
    if(ck==0)
        printf("0");
    else
    {
        ll ck3=0;
        for(i=0; i<n; i++)
        {
            if(t[i]!=s[i])
            {
                ll ck2=0;
                for(j=i; j<n; j++)
                {
                    if(s[j]==t[i])
                    {
                        ck2=1;
                        c=s[j];
                        for(ll k=j; k>=i+1; k--)
                        {
                            s[k]=s[k-1];
                            v.push_back(k);
                        }
                        break;
                    }
                    if(ck2==0 && j==n-1)
                        ck3=1;
                }
            }
        }
        if(ck3==1)
        {
            printf("-1");
        }
        else
        {
            ll x=v.size();
            printf("%lld\n",x);
            for(ll u=0; u<v.size(); u++)
            {
                if(u<v.size()-1)
                    printf("%lld ",v[u]);
                else
                    printf("%lld",v[u]);
            }
        }
    }
    return 0;
}



