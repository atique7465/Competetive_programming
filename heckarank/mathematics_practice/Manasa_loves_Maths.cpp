#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[10];
ll q[10];
int main()
{
    ll t;
    string a;
    scanf("%lld",&t);
    while(t--)
    {
        cin>>a;
        ll ln =a.size();
        if(ln==1)
        {
            if((a[0]-'0')%8==0)
                printf("YES\n");
            else
                printf("NO\n");
        }
        else if(ln==2)
        {
            ll n1=(a[1]-'0')+((a[0]-'0')*10);
            ll n2=(a[0]-'0')+((a[1]-'0')*10);
            if(n1%8==0 || n2%8==0)
                printf("YES\n");
            else
                printf("NO\n");
        }
        else
        {
            for(ll h=0; h<ln; h++)
            {
                arr[a[h]-'0']++;
            }
            if(arr[0]>=3)
            {
                printf("YES\n");
            }
            else
            {
                ll g=0;
                vector<ll>v1,v2;
                ll ck3=0;
                ll x;
                if(arr[0]==2)
                    x=0;
                else if(arr[0]==1)
                {
                    x=8;
                    g=1;
                }
                else
                    x=96;
                for(ll j=1; x<=984; j++)
                {
                    ll ck2=0;
                    x=x+8;
                    if(g==1 && (x==40||x==80))
                    {
                        x=x+8;
                    }
                    ll w=x;
                    while(w>0)
                    {
                        ll ck=0;
                        ll d=w%10;
                        if(arr[d]>0)
                        {
                            if(q[d]==0)
                            {
                                v1.push_back(d);
                                v2.push_back(arr[d]);
                                q[d]++;
                            }
                            arr[d]--;
                            ck=1;
                        }
                        if(ck==0)
                        {
                            ck2=1;
                            break;
                        }
                        w/=10;
                    }
                    if(ck2==1)
                    {
                        for(ll z=0; z<v1.size(); z++)
                        {
                            arr[v1[z]]=v2[z];
                        }
                        for(ll hh=0; hh<10; hh++)
                            q[hh]=0;
                        v1.clear();
                        v2.clear();
                        continue;
                    }
                    else if(ck2==0)
                    {
                        ck3=1;
                        printf("YES\n");
                        break;
                    }
                }
                if(ck3==0)
                    printf("NO\n");
            }
            for(ll zz=0; zz<10; zz++)
                arr[zz]=0;
        }
    }
    return 0;
}
