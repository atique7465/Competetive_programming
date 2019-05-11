#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main()
{
    int n,i,best=1,bsum=1;
    scanf("%d",&n);
    v.push_back(1);
    for(i=2; i*i<=n; i++)
    {
        int sum=0;
        if(n%i==0)
        {
            int k=i,m=i,s;
            while(k>0)
            {
                k/=10;
                s=m-(k*10);
                sum=sum+s;
                m=k;
            }
            if(sum>bsum){
                bsum=sum;
                best=i;
            }
            else if(sum==bsum)
            {
                if(i<best){
                    best=i;}
            }
            v.push_back(i);
        }
    }
    int j;
    for(j=v.size()-1; j>=0; j--)
    {
        if(v[j]*v[j]==n){
            continue;
        }
        int c=n/v[j];
        int k2=c,m2=c,s2,sum2=0;
            while(k2>0)
            {
                k2/=10;
                s2=m2-(k2*10);
                sum2=sum2+s2;
                m2=k2;
            }
            if(sum2>bsum){
                 bsum=sum2;
                best=c;}
            else if(sum2==bsum)
            {
                if(c<best){
                    best=c;}
            }
    }

    printf("%d",best);

    return 0;
}
