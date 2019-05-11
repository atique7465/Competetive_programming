#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,arr[2000];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>arr[i];
        cout<<arr[0]<<" ";
        for(int j=0; j<n-1; j++){
            cout<<(arr[j]*arr[j+1])/(__gcd(arr[j],arr[j+1]))<<" ";
        }
        cout<<arr[n-1]<<endl;
    }
    return 0;
}
