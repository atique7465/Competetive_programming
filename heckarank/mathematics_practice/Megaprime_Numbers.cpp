#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int max_root = (int)std::sqrt(1e15);
std::vector<int>primes;

inline bool hasprimedigitonly(ll n)
{
    while(n>0)
    {
       int d=(ll)(n%10);
       if(d!=2 && d!=3 && d!=5 && d!=7)
       {
           return false;
       }
       n/=10;
    }
    return true;
}

std::vector<int>getprimestill(int max)
{
    assert(max>=1);
    //std::vector<int>primes;
    std::vector<bool>isprime(1+max,true);
    isprime[0]=false;
    isprime[1]=false;
    for(int i=2; i*i<=max; i++)
    {
        if(isprime[i])
        {
            for(int j=i*i; j<=max; j+=i)
            {
                isprime[j]=false;
            }
        }
    }
    for(int i=2; i<(ll)isprime.size(); i++)
    {
        if(isprime[i])
        {
            primes.push_back(i);
        }
    }
    return primes;
}

int countmegaprime(ll f,ll l)
{
    assert(1<=f && l<=(ll)max_root*max_root);
    if(f>l)
    {
        return 0;
    }
    //static std::vector<int>primes= getprimestill(max_root);
    std::vector<bool>isprime(l-f+1,true);
    for(int p : primes)
    {
        ll p2=1LL*p*p;
        if(p2>l)
        {
            break;
        }
        ll from=max(1LL*p,(f+p-1)/p)*p;
        assert(from>=f);
        int from_shifted=(ll)(from-f);
        int l_shifted=(ll)(l-f);
        for(int i=from_shifted; i<=l_shifted; i+=p)
        {
            isprime[i]=false;
        }
    }
    int count=0;
    for(int i=0; i<(ll)isprime.size(); i++)
    {
        if(isprime[i] && hasprimedigitonly(i+f))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    ll f,l;
    scanf("%lld %lld",&f,&l);
    const int chunk = 10 * 1000 * 1000;
    const int chunk_f = 2222222; // 7 digits
    const int chunk_l = 7777777; // 7 digits
    const int L_b_chunk = 777777; // 6 digits
    ll count = 0;
    getprimestill(max_root);
    if(l<=L_b_chunk)
    {
        count=countmegaprime(f,l);
    }
    else
    {
        assert(l>L_b_chunk);
        if(f<=L_b_chunk)
        {
            count=countmegaprime(f,L_b_chunk);
            f=L_b_chunk+1;
        }
        assert(f<=l);
        for(ll partf=f/chunk * chunk + chunk_f; partf<=l; partf+=chunk)
        {
            if(hasprimedigitonly(partf))
            {
                ll partl=partf-chunk_f+chunk_l;
                count+=countmegaprime(std::max(f,partf),std::min(l,partl));
            }
        }
    }
    printf("%lld",count);
    return 0;
}
