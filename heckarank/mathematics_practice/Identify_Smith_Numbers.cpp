#include<bits/stdc++.h>
#define ll long long int
#define ll long long int
using namespace std;
vector<ll>v;
ll status[1000000];

void prime(ll N)
{
    ll i, j, sqrtN;
    sqrtN = int( sqrt((double) N ));
    for( i = 3; i <= sqrtN; i += 2 )
    {
        if( status[i] == 0 )
        {
            for( j = i * i; j <= N; j += i + i )
                status[j] = 1;
        }
    }
    v.push_back(2);
    int ck=1;
    for( i = 3; i <= N; i += 2 )
    {
        if( status[i] == 0 )
        {
            v.push_back(i);
        }
    }
}

int main()
{
    ll n,i,sum1=0,sum2=0;
    scanf("%lld",&n);
    if(n>1)
    {
        int p=int(sqrt((double)n));
        ll k=(ll)p;
        prime(k);
    }
    if(n==1)
        printf("0");
    else
    {
        ll g=n;
        while(g!=0)
        {
            sum1=sum1+g%10;
            g/=10;
        }
        for(i=0; v[i]*v[i]<=n; i++)
        {
            if(n%v[i]==0)
            {
                ll s=0,h=v[i];
                while(h!=0)
                {
                    s=s+h%10;
                    h/=10;
                }
                while(n%v[i]==0)
                {
                    n/=v[i];
                    sum2+=s;
                }
            }
        }
        if(n>1)
        {
            while(n!=0)
            {
                sum2=sum2+n%10;
                n/=10;
            }
        }
        if(sum1==sum2)
            printf("1");
        else
            printf("0");
    }
    return 0;
}
