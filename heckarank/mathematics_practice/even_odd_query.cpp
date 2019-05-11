#include<bits/stdc++.h>
using namespace std;
int arr[100010];
int main()
{
    int n,q,x,y;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&q);
    int c=1;
    while(c<=q)
    {
        scanf("%d%d",&x,&y);
        if((x!=y)&&(arr[x+1]==0))
        {
            printf("Odd\n");
        }

        else
        {
            if(arr[x]%2==0)
            {
                printf("Even\n");

            }
            else
            {
                printf("Odd\n");
            }
        }
        c++;
    }
    return 0;
}
