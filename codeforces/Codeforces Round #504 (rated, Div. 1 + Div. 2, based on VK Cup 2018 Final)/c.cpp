#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n,k,bs,bf;
    scanf("%lld%lld",&n,&k);
    string s;
    cin>>s;
    bs=k/2;
    bf=k/2;
    ll d=0;
    ll ln=s.size();
    for(ll i=0; i<ln; i++)
    {
       // cout<<bs<<" "<<bf<<endl;
      // cout<<endl<<"sd"<<s[i]<<endl;
        if(s[i]=='(')
            d=0;
        if(d==0)
        {
            if(s[i]=='(' && bs>0)
            {
                printf("(");
                bs--;
            }
            else if(s[i]==')' && (bf-1)>=bs && bf>=0)
            {
                printf(")");
                bf--;
            }
        }

        if(d==0 && (bs+bf)==0)
            break;
    }
    return 0;
}

