#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main()
{
    int t,c=1;
    scanf("%d",&t);
    while(c<=t)
    {
        int i,j,count=0,n;
        scanf("%d",&n);
        if(n%2!=0)
        {
            printf("0\n");
        }
        else
        {
            for(i=1; i*i<=n; i++)
            {
                if(n%i==0)
                {
                    v.push_back(i);
                    if(i%2==0)
                    {
                        count++;
                    }
                }
            }

            for(j=v.size()-1; j>=0; j--)
            {
                if(v[j]*v[j]==n)
                {
                    continue;
                }

                if((n/v[j])%2==0)
                {
                    count++;
                }
            }
            v.clear();
            printf("%d\n",count);
        }
        c++;
    }
    return 0;
}

