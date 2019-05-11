#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define sf scanf
#define pf printf

int main()
{
    int test,t,n,m,pos=0,val,ck,a,b,p,cp,i;
    sf("%d",&test);
    char ch[30];
    while(test--)
    {
        pos=0;
        ck=0;
        queue<pii>ql,qr;

        sf("%d %d %d",&n,&t,&m);
        int arr[m+1];

        while(m--)
        {
            scanf("%d",&val);
            scanf("%s",ch);
            ++pos;
            if(strcmp(ch,"left")==0)
            {
                ql.push(make_pair(val,pos));
            }
            else
                qr.push(make_pair(val,pos));

        }
        ck=0;
        cp=1;
        while(!ql.empty()||!qr.empty())
        {
            val=n;
            cp=1;

            while(cp)
            {
                cp=0;

                if(!ql.empty()&&ql.front().first<=ck)
                {

                    while(val--&&!ql.empty()&&ql.front().first<=ck)
                    {
                        b=ql.front().second;
                        arr[b]=ck+t;
                        ql.pop();
                    }
                }
                else if(qr.empty()||(!ql.empty()&&ql.front().first<=qr.front().first))
                {
                    ck=ql.front().first
                    while(!ql.empty()&&val--&&ql.front().first<=ck)
                    {
                        b=ql.front().second;
                        arr[b]=ck+t;
                        ql.pop();
                    }

                }
                else
                    ck=max(ck,qr.front().first);

            }

            ck+=t;
            val=n;
            cp=1;

            while(cp)
            {
                cp=0;
                if(!qr.empty()&&qr.front().first<=ck)
                {

                    while(val--&&!qr.empty()&&qr.front().first<=ck)
                    {
                        a=qr.front().first;
                        b=qr.front().second;
                        arr[b]=ck+t;
                        qr.pop();
                    }
                }
                else if(ql.empty()||(!qr.empty()&&qr.front().first<=ql.front().first))
                {

                    ck=max(ck,qr.front().first);
                    cp=0;
                    while(!qr.empty()&&val--&&qr.front().first<=ck)
                    {
                        a=qr.front().first;
                        b=qr.front().second;
                        arr[b]=ck+t;
                        qr.pop();
                    }

                }
                else
                    ck=max(ck,ql.front().first);
            }
            ck+=t;
        }
        for(i=1; i<=pos; i++)
            printf("%d\n",arr[i]);

        if(test)
            printf("\n");
    }
    return 0;
}
