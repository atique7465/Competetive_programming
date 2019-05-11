#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,ck=1;
    char ch;
    scanf("%d",&t);
    ch=getchar();
    while(t--)
    {
        long long int res=0,m=0,s=0,i=0;
        while(i<100010)
        {
            ch=getchar();
            if(ch=='\n' || ch=='\0')
                break;
            else if(ch=='s')
            {
                s++;
                res=res+m;
            }
            else if(ch=='m')
            {
                m=m+s;
            }
            i++;
        }
        printf("%lld\n",res);
        ck++;
    }
    return 0;
}

