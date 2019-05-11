#include<bits/stdc++.h>
int a, b;
int diva(int d)
{
    int c;
    c=0;
    while(a%d==0)
        a/=d,c++;
    return c;
}

int divb(int d)
{
    int c;
    c=0;
    while(b%d==0)
        b/=d,c++;
    return c;
}

int main()
{
    int d,e,i,ans=0,x[2][4];

    scanf("%d %d",&a,&b);

    x[0][0] = diva(2);
    x[0][1] = diva(3);
    x[0][2] = diva(5);

    x[1][0] = divb(2);
    x[1][1] = divb(3);
    x[1][2] = divb(5);

    if(a!=b)
        printf("-1");
    else
    {
        ans = 0;
        for(i=0; i<3; i++)
            ans+=abs(x[0][i]-x[1][i]);
        printf("%d\n", ans);
    }
    return 0;
}
