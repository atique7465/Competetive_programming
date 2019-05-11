#include<bits/stdc++.h>
using namespace std;
map<int, int> mp;
#define SZ 200005
int ar[SZ];
vector<int> ans;

int main()
{
    int i, n, mx=0, mxval = 0;

    cin>>n;

    for(i=0; i<n; i++)
    {
        scanf("%d",&ar[i]);
        mp[ar[i]] = mp[ar[i]-1]+1;
//        printf("%d %d\n", ar[i], mp[ar[i]]);
        if(mx<mp[ar[i]])
        {
            mxval = ar[i];
            mx = mp[ar[i]];
        }
    }

    for(i=n-1; i>=0; i--)
    {
        if(ar[i] == mxval)
        {
            ans.push_back(i);
            mxval--;
        }
    }

    printf("%d\n", ans.size());
    for(i=ans.size()-1; i>=0; i--)
        printf("%d ",ans[i]+1);

    return 0;
}
