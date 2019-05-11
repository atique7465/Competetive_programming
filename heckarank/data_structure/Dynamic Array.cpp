#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n,q,a,x,y,p,size,y2;
    cin>>n>>q;
    vector<vector<ll> > list(n);
    ll lastAnser=0;
    while(q>0)
    {
        cin>>a>>x>>y;
        if(a==1)
        {
            p=(x^lastAnser)%n;
            list[p].push_back(y);
        }

        else
        {
            p=(x^lastAnser)%n;
            y2=y%list[p].size();
            lastAnser=list[p][y2];
            cout<<lastAnser<<endl;
        }
        q--;
    }

    return 0;
}
