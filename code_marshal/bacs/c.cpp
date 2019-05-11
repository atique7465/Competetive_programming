#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[100];
int main()
{
    ll r=1,i=1,p=10000000000000000;
    while(r<=p)
    {
        r*=2;
        arr[i]=r;
        cout<<r<<endl;
        i++;
    }

    ll t,c=1,j,k,x,l,d,v,m,n;
    scanf("%lld",&t);
    while(c<=t)
    {
        ll ans=0;
        scanf("%lld%lld%lld",&x,&l,&n);
        ll op=n-l+1;
        if(x%2==0)
        {
            if(x>l)
                ans=ans+x-l;
        }

    else if(x>1000000000)
        ans=0;

        else if(x<100000000)
        {
            if(l<x)
            {
                ans=ans+x-l;
                l=x;
            }
            if(l==1)
            {
                d=1;
                if(x==d)
                {
                   // cout<<"k";
                    ans++;
                   // cout<<ans<<endl;
                }
                l=l+1;
            }
            ll s=0,e,ckin=0;
            for(j=l; j<=n; j++)
            {
                //cout<<"l";
                if(s==0)
                {
                    for(k=1; k<=100; k++)
                    {
                        if(arr[k]>j)
                        {
                            m=arr[k-1];
                            e=k-1;
                            s=1;
                            break;
                        }
                    }
                }
                else
                {
                    if(arr[e+1]>j)
                        m=arr[e];
                    else
                    {
                        e++;
                        m=arr[e];
                    }
                }
                d=2*(j-m)+1;

                if(x==d)
                {
                    //cout<<j<<endl;
                    v=j;
                    ans++;
                    ckin=1;
                    break;
                }
            }
            if(ckin==1){
                ll h=2;
                while(h<=v)
                {
                    h*=2;
                }
                if(h>v)
                    h/=2;
                ll count=0;
                while(v<n)
                {
                    v=v+h;
                   //cout<<v<<endl;
                    h*=2;
                    count++;
                }
                if(v>n)
                    count--;
                    //cout<<count<<endl;
                ans=ans+count;
               // cout<<ans<<endl;
            }
        }
        if(ans==0)
            printf("Case %lld: 0/1\n",c);
        else
        {
            ll g=__gcd(ans,op);
            ans/=g;
            op/=g;
            printf("Case %lld: %lld/%lld\n",c,ans,op);
        }
        c++;
    }
    return 0;
}
