#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s1[1100];
string s2[1100];
ll res[1100];
ll n,q,i,j;
int main()
{
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>s1[i];
    }
    cin>>q;
    for(i=1; i<=q; i++)
    {
        cin>>s2[i];
        for(j=1; j<=n; j++)
        {
            if(s2[i]==s1[j])
                res[i]++;
        }
    }

    for(i=1; i<=q; i++)
        cout<<res[i]<<endl;

    return 0;
}
