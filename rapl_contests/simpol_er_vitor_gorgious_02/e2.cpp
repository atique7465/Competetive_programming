#include<bits/stdc++.h>
using namespace std;
char ch[100010];
long long int m[100010];
long long int as[100010];
long long int ak[100010];
long long int ak2[100010];
int main()
{
    int i=1;
    while(i<100010)
        {
            ch[i]=getchar();
            if(ch[i]=='\n' || ch[i]=='\0')
                break;
            else if(ch[i]=='s')
            {
                as[i]=as[i-1]+1;
                m[i]=m[i-1];
                ak[i]=ak[i-1];
                ak2[i]=ak2[i-1];
            }
            else if(ch[i]=='m')
            {
                m[i]=m[i-1]+1;
                as[i]=as[i-1];
                ak[i]=ak[i-1]+as[i];
                ak2[i]=ak2[i-1]+(as[i]*as[i]);
            }
            else
            {
                m[i]=m[i-1];
                as[i]=as[i-1];
                ak[i]=ak[i-1];
                ak2[i]=ak2[i-1];
            }
            i++;
        }
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int res,l,r;
        scanf("%lld%lld",&l,&r);
        res=((ak[r]-ak[l-1])*(as[r]+as[l-1])) - (ak2[r]-ak2[l-1]) - ((as[l-1]*as[r])*(m[r]-m[l-1]));
        printf("%lld\n",res);
    }
    return 0;
}


