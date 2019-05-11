#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t;
    ll n;
    ll a,b,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1 || n ==2 || n==4)
        {
            cout<<2<<endl;
            continue;
        }
        int A[n];
        A[0] = 0;
        for(i= 1 ; i < n ; i++)
            A[i] = -1;
        A[4%n] = 1;
        int temp = 4%n;
        for(i=2 ; i<=n+2 ; i++)
        {
            if(A[(temp*10 + 4) % n] != -1)
            {
                a = i;
                b = A[(temp*10 + 4) % n] ;
                break;
            }
            else
            {
                A[(temp*10 + 4) % n]  = i;
                temp = (temp*10 + 4)%n;
            }
        }
        cout<<2*a-b<<endl;
    }
    return 0;
}
