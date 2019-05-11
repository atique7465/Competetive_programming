#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int t=1;
    while(t<=n)
    {
        int px,py,qx,qy,rx,ry,ck1=1,ck2=1;
        scanf("%d%d%d%d",&px,&py,&qx,&qy);
        printf("%d ",qx+(qx-px));
        printf("%d\n",qy+(qy-py));
      t++;
    }
}
