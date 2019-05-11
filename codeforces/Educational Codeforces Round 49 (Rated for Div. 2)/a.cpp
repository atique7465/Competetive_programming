#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll t,ln;
    scanf("%lld",&t);
    string s;
    while(t--)
    {
        scanf("%lld",&ln);
        cin>>s;
        if(ln==1)
            printf("YES\n");
        else
        {
            ll a=0;
            ll b=ln-1;
            ll ck=0;
            for(ll i=a; i<=(ln/2)-1; i++)
            {
                if(abs((s[i]-'0')-(s[b]-'0'))!=0 && abs((s[i]-'0')-(s[b]-'0'))!=2)
                {
                    ck=1;
                    //cout<<s[i]<<"->"<<(s[i]-'0')<<" "<<s[b]<<"->"<<(s[b]-'0')<<endl;
                }
                b--;
            }
            if(ck==1)
                printf("NO\n");
            else
                printf("YES\n");
        }
    }
    return 0;
}

