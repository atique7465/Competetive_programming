#include<bits/stdc++.h>
using namespace std;
int arr[100010],arr2[100010];
int main()
{
    int i,n,v,count=0;;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&v);
        if(v==0)
            continue;
        else if(v>0)
        {
            if(arr[v]==0)
            {
                count++;
                arr[v]=1;
            }
        }
        else if(v<0)
        {
            v=v*(-1);
            if(arr2[v]==0)
            {
                count++;
                arr2[v]=1;
            }
        }
    }
    printf("%d",count);
    return 0;
}
