#include<bits/stdc++.h>
using namespace std;
int a[999999];
int b[999999];
int main()
{
    int n,m,i,j,g,ck=0,ansj;
    scanf("%d",&n);
    scanf("%d",&m);

    scanf("%d",&a[1]);
    scanf("%d",&a[2]);
    g=__gcd(a[1],a[2]);

    for(i=3; i<=n; i++)
    {
        scanf("%d",&a[i]);
        if(__gcd(a[i],a[i-1])!=g)
        {
            ck=1;
        }
    }

    for(j=1; j<=m; j++)
    {
        scanf("%d",&b[j]);
        if(ck==0 && b[j]==g)
            ansj=j;
    }

    if(ck==0)

    {
        printf("yes\n%d %d",a[0],ansj);
    }
    else
        printf("NO");
    return 0;
}

