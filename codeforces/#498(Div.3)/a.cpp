#include<bits/stdc++.h>
using namespace std;
int arr[2000];
int main()
{
    int n,x,i;
    scanf("%d",&n);
    for (i=1; i<=n; i++)
    {
        scanf("%d",&arr[i]);
    }

    for(i=1; i<=n; i++)
    {
        if(arr[i]%2==0)
        {
            if(i!=n)
                printf("%d ",arr[i]-1);
            else
                printf("%d",arr[i]-1);
        }
        else
        {
            if(i!=n)
                printf("%d ",arr[i]);
            else
                printf("%d",arr[i]);
        }
    }

return 0;
}
