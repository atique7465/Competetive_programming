#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,d,arr[100000],s[100000];
    cin>>n>>d;
    d=d%n;
    if(d==0)
    {
        cin>>arr[0];
        cout<<arr[0];
        for(i=1; i<n; i++)
        {
            cin>>arr[i];
            cout<<" "<<arr[i];
        }
    }
    else
    {
        int p;
        for(i=0; i<n; i++)
        {
            cin>>arr[i];
            p=i+(d);
            if(p>=n)
            {
                s[i]=p-n;
            }
            else
                s[i]=p;
        }
        cout<<arr[s[0]];
        for(i=1; i<n; i++)
        {
            cout<<" "<<arr[s[i]];
        }
    }
    return 0;
}
