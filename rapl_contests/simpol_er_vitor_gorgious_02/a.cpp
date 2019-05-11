#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    string ch;
    scanf("%d",&t);
    while(t--)
    {
        cin>>ch;
        long long int res=0,m=0,s=0;
        int ln=ch.length();
        for(int i=0; i<ln; i++)
        {
            if(ch[i]=='s')
            {
                s++;
                res=res+m;
            }
            if(ch[i]=='m')
            {
                m=m+s;
            }
        }
        printf("%lld\n",res);
    }
        return 0;
    }

