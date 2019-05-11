#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[100];
vector<int>v;
int main()
{
    ll n,ck=1,i,ans=0,check=0;
    scanf("%lld",&n);
    while(ck<=n)
    {
        ll m,d,c=0;
        scanf("%lld%lld",&m,&d);
        if((m>1)&&(d%10<m)&&(d/10<m))
        {
            check=1;
            c=d%10+(d/10)*m;
            if(arr[c]==0)
            {
                v.push_back(c);
            }
            arr[c]++;
        }
        ck++;
    }
    if(check==1){
    for(i=0; i<v.size(); i++)
    {
        ans=ans + (arr[v[i]]*(arr[v[i]]-1))/2;
    }}
    printf("%lld",ans);
    return 0;
}
