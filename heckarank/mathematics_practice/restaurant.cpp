#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(b==0) return a;
    a%=b;
    return gcd(b,a);
}
int main()
{
    int t,c=1;
    scanf("%d",&t);
    while(c<=t)
    {
        int l,b,g;
        scanf("%d%d",&l,&b);
        g=gcd(l,b);
        if(g==1)
        {
            printf("%d\n",l*b);
        }
        else
            printf("%d\n",(l/g)*(b/g));
        c++;
    }
    return 0;
}
