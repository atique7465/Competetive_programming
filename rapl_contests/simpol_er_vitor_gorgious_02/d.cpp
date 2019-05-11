#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i;
    string ch;
    cin>>ch;
    int ln=ch.length();
    scanf("%d",&t);
    while(t--)
    {
        long long int res=0,m=0,s=0,i=0;
        int l,r;
        scanf("%d%d",&l,&r);
        for(int i=l-1; i<r; i++)
        {
            if(ch[i]=='s')
            {
                s++;
                res=res+m;
            }
            else if(ch[i]=='m')
            {
                m=m+s;
            }
        }
     printf("%lld\n",res);
    }
    return 0;
}

