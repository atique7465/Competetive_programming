#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t;
    scanf("%lld",&t);
    ll e=1;
    while(e<=t)
    {
        ll r,c;
        scanf("%lld%lld",&r,&c);
        ll cc=0;
                if(r+2<=8 && c+1<=8)
                    cc++;
                if(r+2<=8 && c-1>=1)
                    cc++;

                if(c+2<=8 && r+1<=8)
                    cc++;
                if(c+2<=8 && r-1>=1)
                    cc++;

                if(r-2>=1 && c+1<=8){
                    cc++;}
                if(r-2>=1 && c-1>=1){
                    cc++;}


                if(c-2>=1 && r+1<=8)
                    cc++;
                if(c-2>=1 && r-1>=1)
                    cc++;

        cout<<"Case "<<e<<": "<<cc<<endl;
        e++;
    }
    return 0;
}
