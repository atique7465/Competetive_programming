#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[300000];

ll gcd(ll x,ll y)
{
    if(y>x)
        return gcd(y,x);
    if(y==0)
        return x;
    return gcd(y, x%y);
}

int main()
{
    ll n,q,i,l,r,x,j;
    scanf("%lld",&n);
    ll f=0;
    for(i=1; i<=n; i++)
    {
        scanf("%lld",&arr[i]);
    }

    scanf("%lld",&q);
    while(q--)
    {
        scanf("%lld%lld%lld",&l,&r,&x);
        if(x==1 || arr[l]==0)
            printf("Yes\n");

        else if(l==r || (arr[l+1]==1 && r>l))
        {
            if(arr[l]%x==0)
                printf("Yes\n");
            else
                printf("No\n");
        }

        else if(arr[l]%x==0 && r>l && arr[l+1]!=0)
            printf("Yes\n");

        else if(r>l && arr[l]!=0 && arr[l+1]==0)
        {
            if(x==1)
              printf("Yes\n");
            else
              printf("No\n");
        }

        else
        {
            ll d=arr[l];
            ll step=0,g=0;
            while(g!=1)
            {
                g=gcd(d,x);
                if(g==1)
                {
                    if(x!=1)
                    {
                        printf("No\n");
                        break;
                    }
                    else
                    {
                        ll max=arr[l+1];
                        if(max>=step-1 && r==l+1)
                            printf("Yes\n");
                        for(ll z=l+2; z<=r; z++)
                        {
                            if(max>=step-1 || arr[z]>=step-1)
                            {
                                printf("Yes\n");
                                break;
                            }
                            else
                                max=pow(max,arr[z]);
                        }
                        if(max<step-1)
                        {
                            printf("No\n");
                        }
                    }
                    break;
                }
                x/=g;
                step++;
            }
        }
    }
    return 0;
}

