#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,k;
    scanf("%lld%lld",&n,&k);
    string t;
    cin>>t;
    ll ln=t.size();
    ll c=0,j=n-1;
    for(ll i=0; i<n; i++)
    {
        if(i>=j)
        {
            if(ln>1 && i==j && t[i]==t[i+1])
                c+=1;
            break;
        }
        if(t[i]==t[j])
            c++;
         else
                break;
        j--;
    }
    //cout<<"C="<<c<<endl;
    if(c==0)
    {
        while(k--)
            cout<<t;
    }
    else
    {
        cout<<t;
        k-=1;
        while(k--)
        {
            for(ll a=c; a<n; a++)
            {
                cout<<t[a];
            }
        }
    }
    return 0;
}
