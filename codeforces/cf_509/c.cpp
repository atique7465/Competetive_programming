#include<bits/stdc++.h>
#define ll long long
#define sz 200009
using namespace std;
vector<ll>v;
map<ll,ll>mp;
set<long long>s;
set<long long>::iterator it;

int main()
{
    ll n,m,d,a,b,x,y,i,j,k=0;
    scanf("%I64d %I64d %I64d",&n,&m,&d);
    for(i=0; i<n; i++)
    {
        scanf("%I64d",&a);
        v.push_back(a);
        s.insert(a);
    }
    j=1;
    a=0;
    while(true)
    {

        it=s.lower_bound(a);
        a=*it;
        mp[a]=j;
        s.erase(*it);
        if(s.empty())
            break;

        k=*s.rbegin();

        if(a+d+1>k)
            a=0,j++;
        else
          a=a+d+1;

    }
    printf("%I64d\n",j);
    for(i=0;i<n;i++)
        printf("%I64d ",mp[v[i]]);
    printf("\n");
    return 0;
}

