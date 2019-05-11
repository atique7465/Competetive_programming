#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll mod_pow(ll a,ll b, ll m)
{
    ll res=1;
    while(b>0)
    {
        if(b%2==1)
        {
            res=res*a;
            if(res>m)
                res%=m;
        }
        a=a*a;
        if(a>m)
            a%=m;
        b/=2;
    }
    return res;
}

ll num(string s, ll m)
{
    ll ln=s.size(),res=0;
    for(ll i=0; i<ln; i++)
    {
        res=((res*10)%m+(s[i]-'0'))%m;
    }
    return res;
}

int main()
{
    ll t;
    ll m=1e9+7;
    scanf("%lld",&t);
    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        ll a=num(s1,m);
        ll b=num(s2,m-1);
        if(b==0)
            printf("1\n");
        else
        {
            ll ans=mod_pow(a,b,m);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
