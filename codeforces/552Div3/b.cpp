#include<bits/stdc++.h>
using namespace std;

int arr[101],d;
vector<int>v;

int main()
{
    int n,sum=0,mx=0,i,j,mn=101;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&arr[i]);
        sum=sum+arr[i];
        if(arr[i]>mx)
            mx=arr[i];
        if(arr[i]<mn)
            mn=arr[i];
    }
    if(n==1 || mx==mn)
        printf("0");
    else
    {
    int val=sum/n;
    int check=0;
    for(i=1; i<=mx; i++)
    {
        int ck=0,ccc=0;
        for(j=1; j<=n; j++)
        {
            if(arr[j]==i)
            {
                continue;
            }
            else if(arr[j]<i)
            {
                if(ck==0)
                {
                    d=i-arr[j];
                    ck=1;
                }
                else if(i-arr[j]!=d)
                {
                    ccc=1;
                    break;
                }
            }
            else
            {
                if(ck==0)
                {
                    d=arr[j]-i;
                    ck=1;
                }
                else if(arr[j]-i!=d)
                {
                    ccc=1;
                    break;
                }
            }
        }
        if(ccc==0)
        {
            v.push_back(d);
            check=1;
        }
    }

    if(check==0)
        printf("-1");
    else
    {
        sort(v.begin(),v.end());
        printf("%d",v[0]);
    }
    }
    return 0;
}
