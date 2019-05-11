#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll check(ll p,ll n)
{
    ll c=0;
    for(ll i=5; i<=p; i*=5)
    {
        c+=p/i;
        if(p/i==0)
            break;
    }
    return c;
}

int main()
{
    /// read discussion for observation for this solution
    ll t,n;
    scanf("%lld",&t);
    while(t--)
    {
        /// we can do it in this way or,
        ///we can binary search between [0,5n] by check function.
        scanf("%lld",&n);
        ll q;
        for(ll i=4*n+1; i=i; i++)
        {
            if(i%5==0)
            {
                q=i;
                break;
            }
        }

        for(ll i=q; i=i; i+=5)
        {
            ll c=check(i,n);
            if(c>=n)
            {
                printf("%lld\n",i);
                break;
            }
        }
    }
    return 0;
}

/// solution 2
/*
#include<bits/stdc++.h>

using namespace std;

bool check(long long int p, long long int n)
{
    long long int temp = p , outp =0, five = 5;
    while(five < temp)
    {
        outp += temp/five;
        five = five*5;
    //    cout<<temp<<" "<<five<<endl;
    }
    if(outp>= n)
            return true;
    else
            return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        if(n==1)
        {
            cout<<"5"<<endl;
            continue;
        }
        long long int low =0;
        long long int high = 5*n;
        while(low <high)
        {
            long long int mid = (low+high)/2;
            if(check(mid,n) == true)
                    high = mid;
            else
                    low = mid+1;
        }
        cout<<low<<endl;
    }
    return 0;
}*/
