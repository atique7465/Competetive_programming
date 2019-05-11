#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,sqrtm,k,m=1000,t,l;
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
    prime.push_back(1);
    prime.push_back(2);
    for(i=3; i<=m; i+=2)
    {
        if(status[i>>1]==0)
            prime.push_back(i);
    }

  scanf("%d",&t);
  for(k=1; k<=t; k++)
  {
     scanf("%d",&n);
      for(l=0; prime[l]<=n; l++){
           printf("%d\n",prime[l]);}
     printf("\n");
  }
   return 0;
}
