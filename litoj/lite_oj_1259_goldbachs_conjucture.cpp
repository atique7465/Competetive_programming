#include<bits/stdc++.h>
using namespace std;
int m=10000000;
int status[5000001];
int main()
{
    int n,i,j,sqrtm,k,Q,l;
    vector<int>prime;
    sqrtm=int(sqrt((double)m));

    for(i=1; i<=m>>1; i++)
    {
        status[i]=0;
    }

    for(i=3; i<=sqrtm; i+=2)
    {
        if(status[i>>1]==0)
        {
            for(j=i*i; j<=m; j+=2*i)
                status[j>>1]=1;
        }
    }
    prime.push_back(2);
    for(i=3; i<=m; i+=2)
    {
        if(status[i>>1]==0)
            prime.push_back(i);
    }

    int t,p=1;
    scanf("%d",&t);
    while(p<=t)
    {
        scanf("%d",&n);
        if(n==4)
            printf("Case %d: 1\n",p);
        else
        {
            int count=0;
            for(k=0; prime[k]<=(n/2); k++)
            {
                int l=n-prime[k];
                //cout<<prime[k]<<endl;
                if(l%2!=0)
                {
                    if(status[l>>1]==0)
                    {
                        // cout<<n<<" = "<<prime[k]<<" + "<<l<<endl;
                        //printf("%d = %d + %d\n",n,prime[k],l);
                        //break;
                        count++;
                    }
                }
            }
            printf("Case %d: %d\n",p,count);
        }
        p++;
    }
    return 0;
}

