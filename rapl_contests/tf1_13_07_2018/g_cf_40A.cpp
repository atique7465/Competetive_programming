#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y,ck1=0,ck2=0;
    scanf("%d%d",&x,&y);
    if(x==0 || y==0)
        printf("black\n");
    else{
    if((x>0 && y>0 ) || (x<0 && y<0))
        ck1=1;
    else
        ck2=1;
    double s=(x*x)+(y*y);
    double d=sqrt(s);
    int k=int(sqrt(s));
    double r=d-((double)k);
    if(r==0.0)
        printf("black\n");
    else
    {
        if(ck1==1 && k%2==0){
            printf("black\n");
        }
        else if(ck1==1 && k%2!=0){
            printf("white\n");}
        else if(ck2==1 && k%2==0){
            printf("white\n");
        }
        else
        {
            printf("black\n");
        }
    }
    }
    return 0;
}
