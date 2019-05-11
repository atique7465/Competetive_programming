#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int i,n,m,a,b,k,sum=0,c=1;
    scanf("%lld%lld",&n,&m);

    while(c<=m)
    {
        scanf("%lld%lld%lld",&a,&b,&k);
        sum=sum+((b-a+1)*k);
        c++;
    }
    printf("%lld",sum/n);
    return 0;
}

