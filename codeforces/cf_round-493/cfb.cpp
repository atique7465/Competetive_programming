#include<bits/stdc++.h>
using namespace std;
int n,b,c=1,k=0,l=0;
int j[101];
int bj[101];
int v[101];
vector<int>m;
int main()
{
    scanf("%d%d",&n,&b);
    while(c<=n)
    {
        scanf("%d",&v[c]);
        if(v[c]%2==0)
        {
            k++;
            j[c]=k;
            bj[c]=bj[c-1];
        }
        else
        {
            l++;
            bj[c]=l;
            j[c]=j[c-1];
        }
        c++;
    }
    for(int i=2; i<=n-2; i+=2)
    {
        int d;
        if(v[i]>v[i+1])
            d=v[i]-v[i+1];
        else
            d=v[i+1]-v[i];
        if((d<=b) && j[i]==bj[i] && j[n]-j[i]==bj[n]-bj[i] ){
            m.push_back(d);}
    }
    sort(m.begin(),m.end());
    int count=0;
    for(int t=0; t<m.size(); t++)
    {
        if(m[t]<=b)
        {
            count++;
            b=b-m[t];
        }
    }
    printf("%d",count);

    return 0;
}

