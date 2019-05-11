#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,sqrtm,k,m=42768;
    vector<int>prime;
    int status[(m/2)+1];

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

    while(scanf("%d",&n)&&n)
    {
        if(n==4)
            printf("1\n");
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
            printf("%d\n",count);
        }
    }
    return 0;
}
