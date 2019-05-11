#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
map<ll, ll> freq;
ll ar[200005];

int main()
{
    ll i, j, n, k, ans=0, sum=0, x, cnt;
    ll pos, neg;

    cin>>n;

    for(i=0; i<n; i++)
    {
        scanf("%llu",&ar[i]);
        sum+=ar[i];
        freq[ar[i]]++;
    }
    pos = neg = 0;
    for(i=0; i<n; i++)
    {
        x = (ar[i]*freq[ar[i]]);
        x += (ar[i]+1)*freq[ar[i]+1];
        x += (ar[i]-1)*freq[ar[i]-1];

        cnt = freq[ar[i]];
        cnt += freq[ar[i]+1];
        cnt += freq[ar[i]-1];

        pos += (sum-x);
        neg += ( (ar[i]*(n-i-cnt)));
        freq[ar[i]]--;
        sum-=ar[i];

//        cout<<ans<<"  "<<cnt<<"\n";
    }

    if(neg>pos)
        printf("-%llu", neg-pos);
//        cout<<-(neg-pos);
    else
        cout<<pos-neg;
//    cout<<ans;

    return 0;
}
