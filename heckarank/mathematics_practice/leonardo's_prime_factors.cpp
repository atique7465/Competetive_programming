#include<bits/stdc++.h>
using namespace std;
int v[17]={2, 3 ,5, 7, 11, 13 ,17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
/*vector<long long int>v;
long long int N=60;
long long int status[60];

void prime()
{
    long long int i, j, sqrtN;
    //for( i = 2; i <= N; i++ ) status[i] = 0;
    sqrtN = int( sqrt((double) N ));
    for( i = 3; i <= sqrtN; i += 2 ) {
        if( status[i] == 0 ) {
            for( j = i * i; j <= N; j += i + i )
                status[j] = 1;
        }
    }
    v.push_back(2);
    for( i = 3; i <= N; i += 2 ) {
        if( status[i] == 0 )
            v.push_back(i);
    }
}*/

void primefactorize(unsigned long long int x)
{
    int i;
    int count=0;
    unsigned long long int sum=1;
    for(i=0; sum<=x; i++)
    {
            sum=sum*v[i];
            count++;
    }
    printf("%d\n",count-1);
}

int main()
{
    //prime();
    int q;
    scanf("%d",&q);
    int ck=1;
    while(ck<=q)
    {
       unsigned long long int x;
        scanf("%llu",&x);
        primefactorize(x);
        ck++;
    }
    return 0;
}
