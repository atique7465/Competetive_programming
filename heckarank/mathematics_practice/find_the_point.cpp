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
        if(px>qx)
            rx=px-qx;
        else if(px==qx){
            ck1=0;
            rx=px;
            }
        else
            rx=qx-px;

        if(py>qy)
               ry=py-qy;
        else if(py==qy){
            ck2=0;
            ry=py;
            }
        else
            ry=qy-py;
      if(ck1==1)
      {
          if(qx>px)
            rx=qx+rx;
            else
                rx=qx-rx;
           printf("%d ",rx);
      }
      else
        printf("%d ",rx);
       if(ck2==1)
      {
          if(qy>py)
              ry=qy+ry;
            else
                ry=qy-ry;
           printf("%d\n",ry);
      }
      else
        printf("%d\n",ry);

      t++;
    }
}
