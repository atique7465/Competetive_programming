#include <bits/stdc++.h>
using namespace std;
vector<long long int>v;
long long int np =1000010;
long long int status[1000011];
long long int n,i,j,ans,ck,tc,cas=1;

void prime()
{
    for( i = 2; i<= np; i++ )
        status[i] = 0;
    for( i = 3; i*i <= np; i += 2 )
    {
        if( status[i] == 0 )
        {
            for( j = i * i; j <= np; j += i + i )
                status[j] = 1;
        }
    }
    v.push_back(2);
    for( i = 3; i <= np; i += 2 )
    {
        if( status[i] == 0 )
            v.push_back(i);
    }
}

int main()
{
    prime();
    scanf("%lld",&tc);
    while(cas<=tc)
    {
        scanf("%lld",&n);
        ans=1;
        if(n==1)
        {
            printf("Case %lld: 0\n",cas);
            cas++;
        }
        else if (n%2!=0 && n<1000000 && status[n]==0)
        {
            printf("Case %lld: 1\n",cas);
            cas++;
        }

        else
        {
            for(i=0; v[i]*v[i]<=n; i++)
            {
                ck=0;
                if(n%v[i]==0)
                {
                    while(n%v[i]==0)
                    {
                        n/=v[i];
                        ck++;
                    }
                  ans=ans*(ck+1);
                }
            }
            if( n > 1 )
            {
                 ans=ans*2;
            }
        printf("Case %lld: %lld\n",cas,ans-1);
        cas++;
        }
    }
        return 0;
    }
