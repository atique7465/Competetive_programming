#include<bits/stdc++.h>
using namespace std;
int arr[11];
int arr2[11];
int main()
{
    int n,c=1,ck=1;
    scanf("%d",&n);
    while(c<=n)
    {
        scanf("%d",&arr2[c]);
        arr[c]=arr[c-1]+arr2[c];
        c++;
    }
    if(n==1)
        printf("-1");
    else if(n==2)
    {
        if(arr2[1]!=arr2[2]){
            cout<<"1"<<endl<<"1";
    }
        else
            printf("-1");
    }
    else if(n>2)
    {
        for(int k=n-1; k>=1; k--)
        {
            if(arr[k]!=arr2[n])
            {
                cout<<k<<endl;
                cout<<"1";
                    for(int e=2; e<=k; e++)
                    cout<<" "<<e;
               break;
            }
        }
    }
    return 0;
}
