#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,c=1;
    scanf("%d",&t);
    while(c<=t)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>b)
            printf("Argentina %d - %d Brazil\n",a,b);
        else
            printf("Brazil %d - %d Argentina\n",b,a);
        c++;
    }
    return 0;
}
