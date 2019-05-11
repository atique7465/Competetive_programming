#include<bits/stdc++.h>
using namespace std;
int k=5010;
int status[2506];
vector<int>v;
int main()
{
    int i,j,sqrtk,t,p=1;
    sqrtk=int(sqrt((double)k));
    for(i=3; i<=sqrtk; i+=2)
    {
        if(status[i>>1]==0)
        {
            for(j=i*i; j<=k; j+=2*i)
                status[j>>1]=1;
        }
    }
    //printf("2 ");
    /* v.push_back(2);
     for(i=3; i<=k; i+=2)
     {
         if(status[i>>1]==0)
             //printf("%d ",i);
             v.push_back(i);
     }
     cout<<v.size()<<endl;
     for(i=0; i<v.size(); i++)
         cout<<v[i]<<" ";*/

    scanf("%d",&t);
    int n,m;
    while(p<=t)
    {
        scanf("%d",&n);
        //m=n/2+1;
        if(n==2||n==3)
            printf("2\n");
        else
        {
            for(m=(n/2)+1; m<n; m++)
            {
                if(m%2!=0)
                {
                    if(status[m>>1]==0){
                        printf("%d\n",m);
                        break;}
                }
            }
        }
        p++;
    }

    return 0;
}
