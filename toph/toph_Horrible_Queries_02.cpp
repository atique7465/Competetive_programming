#include<bits/stdc++.h>
using namespace std;
int a[100000],arr[51][100000];
int main()
{
    int n,f,i,p,q,j,l,r,k,m,start,end,mid;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }

    for(i=1; i<=50; i++)
    {
        for(j=0; j<n; j++)
        {
            if(a[j]==i)
            {
                arr[i][j]+=1;
            }
            arr[i][j]=arr[i][j]+arr[i][j-1];
            //cout<<arr[i][j]<<" ";
        }
        //cout<<endl;
    }

    scanf("%d",&q);
    p=1;
    while(p<=q)
    {
        scanf("%d%d%d",&l,&r,&k);
        int count=0;
        for(i=1;i<=50; i++)
        {//cout<<"L";
            if((arr[i][r-1]-arr[i][l-2])>=k){
                   // cout<<"K";
                count++;}
        }
        cout<<count<<endl;
        p++;
    }
    return 0;
}
