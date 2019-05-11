#include<bits/stdc++.h>
using namespace std;
const int inf =1000001000;
#define sz 1000000
int arr[sz],lis[sz],ck[sz];

int main()
{
    int n,i,j,len,lo,hi,mi;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
     ck[0]=-1;
     for(i=1;i<=n;i++)
        ck[i]=inf;
     len=0;

     for(i=0;i<n;i++)
     {
         lo=0;hi=len;
         while(lo<=hi)
         {
             mi=(lo+hi)>>1;
             if(ck[mi]<arr[i])
                lo=mi+1;
             else
                hi=mi-1;
         }
         ck[lo]=arr[i];
         len=max(len,lo);
         lis[i]=lo;
     }

     printf("%d\n",len);

    return 0;
}

