#include<bits/stdc++.h>
using namespace std;
int m=87000008;
int status[43500005];
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

    scanf("%d",&Q);
    for(i=1; i<=Q; i++)
    {
        scanf("%d",&k);
        printf("%d\n",prime[k-1]);
    }
    return 0;
}
