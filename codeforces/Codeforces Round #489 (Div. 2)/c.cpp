 #include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;
ll mod=1000000007;
ll pow(ll a, ll b)
{
    ll ans = 1;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            ans=(ans*a);
            if(ans>mod)
                ans%=mod;
        }
        a = (a*a);
        if(a>mod)
            a%=mod;
        b /= 2;
    }
    return ans;
}

int main()
{
    ll x,k,pw,w=2,p1,p2,p;
    scanf("%llu%llu",&x,&k);
    if(x==0)
        printf("0");
    else
    {
        pw=pow(w,k);
        p1=(((x-1+mod)%mod * pw)%mod +1) %mod;
        p2=((x%mod)*pw)%mod;
        p=(p1+p2)%mod;
        printf("%lld",p);
    }
    return 0;
}
