#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int arr[200];
int main()
{
    int n,m,i,j,a,b;
    scanf("%d%d",&n,&m);
    for(i=1; i<=n; i++)
    {
        scanf("%d%d",&a,&b);
        for(j=a; j<=b; j++)
           arr[j]=1;
    }
    ll c=0;
    for(i=1; i<=m; i++)
    {
        if(arr[i]==0)
            c++;
    }
    printf("%d\n",c);
    for(i=1; i<=m; i++)
    {
        if(arr[i]==0)
        {
            if(i<m)
                printf("%d ",i);
            else
                printf("%d",i);
        }
    }
    return 0;
}


