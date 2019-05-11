#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
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
        int x1,y1,x2,y2,ans=0;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%d\n",gcd(abs(x2-x1),abs(y2-y1))-1);
        c++;
    }
    return 0;
}
