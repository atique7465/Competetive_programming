#include<bits/stdc++.h>
using namespace std;
int main()
{
    float hh,mm,h,d,c,n,mint=0,ck1=0,ck2=0,tot1=0,tot2=0,dis=0;
    scanf("%f%f",&hh,&mm);
    if(hh<20)
    {
        mint=mint+(60-mm);
        hh++;
        mint=mint+((20-hh)*60);
        //cout<<mint<<" ";
    }

     scanf("%f%f%f%f",&h,&d,&c,&n);
     tot1=h+(mint*d);
     tot1=ceil(tot1/n);
     ck1=tot1*c;
     //cout<<ck1<<" ";
     dis=(ck1*20)/100;
     ck1=ck1-dis;
    // cout<<ck1<<" "<<dis<<" ";

     tot2=ceil(h/n);
     ck2=tot2*c;
      if(ck1>ck2)
        printf("%.4f\n",ck2);
      else
        printf("%.4f\n",ck1);

    return 0;
}
