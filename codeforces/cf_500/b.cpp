#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll a[100010];
ll b[100010];
ll ck[100010];
ll ck2[100010];
ll v[100010];
int main()
{
    ll n,x,i,j;
    scanf("%lld%lld",&n,&x);
    ll d1=0;
    for(i=1; i<=n; i++)
    {
        scanf("%lld",&a[i]);
        ck[a[i]]++;
        if(ck[a[i]]==2)
            d1=1;
    }
     for(i=1; i<=n; i++)
           cout<<a[i]<<" "<<ck[a[i]]<<endl;
    if(d1==1)
        printf("0");
    else
    {
        ll d2=0;
        ll ans2=0,ans3=1;
        for(i=1; i<=n; i++)
        {
            b[i]=(a[i]&x);
            ck2[b[i]]++;
            if(ck2[b[i]]>1)
                ans3=0;
            if(b[i]!=a[i] && ck[b[i]]==1){
                    cout<<b[i]<<ck[b[i]]<<endl;
               ans2=1;
               break;}
        }
        if(ans2==1)
            printf("1");
        else if(ans3==1)
            printf("-1");
        else
            printf("2");
    }
    return 0;
}

