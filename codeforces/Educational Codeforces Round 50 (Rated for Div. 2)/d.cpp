#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll a[400000];
ll b[400000];
int main()
{
    ll n,m;
    scanf("%lld",&n);
    for(ll i=1; i<=n; i++)
        scanf("%lld",&a[i]);
    scanf("%lld",&m);
    for(ll j=1; j<=m; j++)
        scanf("%lld",&b[j]);

    ll max=m+n;
    ll c=0;
    ll x=1,y=1;
    ll s1=0,s2=0;
    ll dd1=0,dd2=0;
    for(ll i=1; i<=max; i++)
    {
        s1=a[x];
        s2=b[y];
        if(s1==s2)
        {
            c++;
            ll s1=0,s2=0;
            if(x>=n && y>=m)
            {
                printf("%lld",c);
                break;
            }
            else
            {
                x++;
                y++;
                continue;
            }
        }

        if(s1<s2)
        {
            x++;
            while(s1<b[y])
            {
                s1+=a[x];
                if(s1<s2 && x>=n)
                {
                    dd1=1;
                    break;
                }
                if(s1>=s2)
                {
                    a[x]=s1;
                    break;
                }
                x++;
            }
            if(dd1==1)
            {
                printf("-1");
                break;
            }
            else
                continue;
        }

        if(s2<s1)
        {
            y++;
            while(s2<a[x])
            {
                s2+=b[y];
                if(s2<s1 && y>=m)
                {
                    dd2=1;
                    break;
                }
                if(s2>=s1)
                {
                    b[y]=s2;
                    break;
                }
                y++;
            }
            if(dd2==1)
            {
                printf("-1");
                break;
            }
            continue;
        }
    }
    return 0;
}

