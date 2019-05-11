#include<bits/stdc++.h>
using namespace std;
long long int arr[300000];
int main()
{
    long long int n,i,ans=0;
    scanf("%lld",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%lld",&arr[i]);
    }
    long long int l=1,r=n,suml=arr[1],sumr=arr[n];
    for(i=1; i<=n; i++)
    {
        //cout<<l<<" "<<r<<endl;
        if(l>=r)
        {
            //cout<<"K";
            break;
        }
        else if(suml==sumr)
        {
            ans=suml;
            l++;
            suml=suml+arr[l];
        }
        else if(suml<sumr)
        {
            l++;
            suml=suml+arr[l];
        }
        else if(suml>sumr)
        {
            r--;
            sumr=sumr+arr[r];
        }
    }
    printf("%lld",ans);
    return 0;
}
