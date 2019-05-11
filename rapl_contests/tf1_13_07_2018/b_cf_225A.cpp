#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,n,ck=0;
    scanf("%d%d",&n,&x);
    x=7-x;
    int a,b;
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&a,&b);
        if(x==a || x==b)
                ck=1;
        if(7-x==a || 7-x==b)
            ck=1;
    }
    if(ck==0)
        printf("YES");
    else
        printf("NO");
    return 0;
}
