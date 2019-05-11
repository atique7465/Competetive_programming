#include<bits/stdc++.h>
using namespace std;
vector<long long int>v1,v2;
int main()
{
    int tc,c=1;
    scanf("%d",&tc);
    while(c<=tc)
    {
        long long int p,l,q=0;
        scanf("%lld%lld",&p,&l);
        q=p-l;
        if(q<=l)
        {
            printf("Case %d: impossible\n",c);
            c++;
        }

        else
        {
            int sqrtq=int(sqrt((double)q));
            for( int i=1; i<=sqrtq; i++)
            {
                if(q%i==0)
                {
                    v1.push_back(i);
                    v2.push_back(i);
                }
            }
            for(int j=v1.size()-1; j>=0; j--)
            {
                v2.push_back(q/v1[j]);
            }
            printf("Case %d:",c);

            for(int t=v2.size()-1; t>=0; t--)
            {
                //unsigned long long int s,w;
                //s=p/v2[t];
                if(v2[t]==v2[t-1])
                    continue;
                if(((q/v2[t])>l)&&(q%v2[t]==0))
                {
                   printf(" %lld",q/v2[t]);
                   if(v2[t]==1)
                    break;
                }
            }
            printf("\n");
            c++;
            v1.clear();
            v2.clear();
        }

    }
    return 0;
}
