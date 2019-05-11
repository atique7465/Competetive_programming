#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll>v1,v2,m;
int main()
{
    ll n,k,i,j,p,sum=0;
    scanf("%lld%lld",&n,&k);
    for(i=0; i<n; i++)
    {
        scanf("%lld",&p);
        v1.push_back(p);
        v2.push_back(p);
    }
    sort(v2.begin(),v2.end());
    m.push_back(v2[v2.size()-1]);
    sum=sum+v2[v2.size()-1];
    int t=1;
    for(i=v2.size()-2; i>=0; i--)
    {
        if(t<=k-1)
        {
            m.push_back(v2[i]);
            sum=sum+v2[i];
            t++;
        }
        if(t==k)
            break;
    }
    printf("%lld\n",sum);

    for(int e=0; e<m.size(); e++)
    {
        for(i=0; i<n; i++)
        {
            if(v1[i]==m[e])
            {
                v1[i]=0;
                m[e]=i;
                break;
            }
        }
    }



    sort(m.begin(),m.end());

    int w=0;
    for(int e=0; e<m.size(); e++)
    {
        if(e==m.size()-1)
            printf("%lld",n-w);
        else
        {
            printf("%lld ",m[e]+1-w);
            w=m[e]+1;
        }
    }
    return 0;
}
