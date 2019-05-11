#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,k,c=1;
    cin>>t;
    while(c<=t)
    {
        int res=0;
        cin>>n>>m>>k;
        res=min(n,min(m,k));
        n-=res;
        m-=res;
        k-=res;
        n/=2;
        res=res+min(n,k);
        cout<<"Case "<<c<<": "<<res<<endl;
        c++;
    }
    return 0;
}
