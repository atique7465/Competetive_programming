#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if(b==0) return a;
    else
    {
        a%=b;
        return gcd(b,a);
    }
}
int main()
{
    int t,h=1;
    scanf("%d",&t);
    while(h<=t)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(c<=max(a,b))
        {
            if((c%gcd(a,b))==0)
                printf("YES\n");
            else
                printf("NO\n");
        }
        else
        {
            printf("NO\n");
        }
        h++;
    }
    return 0;
}
