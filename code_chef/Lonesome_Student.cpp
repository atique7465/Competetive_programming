#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t,p=1,i,k;
    vector<long long int>v;
    scanf("%d",&t);
    while(p<=t)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d",&k);
            v.push_back(k);
        }

        sort(v.begin(),v.end());

        for(i=0; i<v.size(); i++)
        {
            if(v[i]!=v[i+1]||i==v.size()-1)
                printf("%d\n",v[i]);
            else
            {
                i++;
            }
        }

       v.erase(v.begin(),v.end());

        p++;
    }

    return 0;
}
