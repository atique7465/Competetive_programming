#include<bits/stdc++.h>
using namespace std;
int main()
{
        long long int r,c;
        long long int n=0;
        scanf("%lld%lld",&r,&c);
        if(r%2==0)
        {

            n=(((r-1)/2)*5)+c;

            printf("%lld\n",(2*n)-1);
        }
        else
        {
            n=(((r-1)/2)*5)+c;
            printf("%ld\n",(2*n)-2);
        }
    return 0;
}

