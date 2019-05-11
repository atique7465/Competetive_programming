#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int arr[100010];

int main()
{
    int t,n,nm,n1,n2,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n==1)
        {
            scanf("%d",&nm);
            if(nm==1)
                printf("YES\n");
            else
                printf("NO\n");
        }
        else
        {
            scanf("%d",&n1);
            arr[n1]++;
            v.push_back(n1);
            scanf("%d",&n2);
            arr[n2]++;
            v.push_back(n2);
            ans=__gcd(n1,n2);
            n=n-2;
            if(n>0){
            while(n--)
            {
                scanf("%d",&nm);
                if(arr[nm]==0)
                {
                    ans=__gcd(ans,nm);
                    arr[nm]++;
                    v.push_back(nm);
                }
            }}

            //cout<<"count="<<count<<endl;
            if(ans>=2)
                printf("NO\n");
            else
                printf("YES\n");

            for(int t=0; t<v.size(); t++)
            {
                arr[v[t]]=0;
            }
            v.clear();
        }
    }
    return 0;
}
