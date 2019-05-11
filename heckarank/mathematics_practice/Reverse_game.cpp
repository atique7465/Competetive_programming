#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, c=1;
    scanf("%d",&t);
    while(c<=t)
    {
        int i,n,k;
        scanf("%d%d",&n,&k);
        if(k<n/2)
            printf("%d\n",(2*k)+1);
        else if(k>=n/2)
            printf("%d\n",2*(n-k-1));
        c++;
    }
    return 0;
}
