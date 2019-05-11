#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll>v1,v2;
int main()
{
    ll n;
    scanf("%lld",&n);
    for(ll i=1; i<=n; i++)
    {
        ll a;
        scanf("%lld",&a);
        v1.push_back(a);
    }
    for(ll j=1; j<=n; j++)
    {
        ll b;
        scanf("%lld",&b);
        v2.push_back(b);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    ll s1=0,s2=0;
    for(ll i=1; i<=2*n; i++)
    {
        if(v1.size()==0 && v2.size()==0)
            break;
        if(i%2!=0)
        {
            if(v1.size()>0)
            {
                if(v2.size()>0)
                {
                    if(v1[v1.size()-1]>v2[v2.size()-1])
                    {
                        s1+=v1[v1.size()-1];
                        v1.pop_back();
                    }
                    else
                        v2.pop_back();
                }
                else
                {
                    s1+=v1[v1.size()-1];
                    v1.pop_back();
                }
            }
            else
                v2.pop_back();
        }

        else
        {
            if(v2.size()>0)
            {
                if(v1.size()>0){
                if(v2[v2.size()-1]>v1[v1.size()-1])
                {
                    s2+=v2[v2.size()-1];
                    v2.pop_back();
                }
                else
                    v1.pop_back();
                }
                else
                {
                    s2+=v2[v2.size()-1];
                    v2.pop_back();
                }
            }
            else
                v1.pop_back();
        }
    }
    printf("%lld",(s1-s2));
    return 0;
}

