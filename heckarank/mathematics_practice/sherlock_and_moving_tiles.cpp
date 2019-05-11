#include<bits/stdc++.h>
using namespace std;
int main()
{
    double l,s1,s2,q1,ans,a,b;
    cin>>l>>s1>>s2;
    if(s1>s2)
    {
        a=s1;
        b=s2;
    }
    else
    {
        a=s2;
        b=s1;
    }
    int q,c=1;
    cin>>q;
    while(c<=q)
    {
        ans=0;
        cin>>q1;
        if(q1==l*l)
            cout<<"0.00000"<<endl;
        else
        {
        ans=((l-sqrt(q1))*sqrt(2))/(a-b);
        printf("%.05lf\n",ans);
        }
            c++;
    }
    return 0;
}
