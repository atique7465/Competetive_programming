#include<bits/stdc++.h>
using namespace std;
vector<int>prime;
int arr[100];
int main()
{
    int n,i,j,sqrtk,k,l,h,q,r;
    k=100;
    int status[101];
    sqrtk=int(sqrt((double)k));

    for(i=1; i<= k>>1; i++)
        status[i]=0;

    for(i=3; i<=sqrtk; i+=2)
    {
        if(status[i>>1]==0)
        {
            for(j=i*i; j<=k; j+=2*i)
                status[j>>1]=1;
        }
    };
    prime.push_back(2);
    for(i=3; i<=k; i+=2)
    {
        if(status[i>>1]==0)
        {
            prime.push_back(i);
        }
    }

    int t,p=1;
    scanf("%d",&t);
    while(p<=t)
    {
        scanf("%d",&n);

        if(n==2)
            printf("Case %d: %d = 2 (1)\n",p,n);   //Case 3: 6 = 2 (4) * 3 (2) * 5 (1)

        else
        {
            for(i=2; i<=n; i++)
            {
                if(i%2!=0&&status[i>>1]==0)
                {
                    arr[i]++;
                }

                else
                {
                    q=i;
                    int sqrtq=int(sqrt((double)q));
                    for(j=0; j<=sqrtq; j++)
                    {
                        if(q%prime[j]==0)
                        {
                            while(q%prime[j]==0)
                            {
                                q/=prime[j];
                                r=prime[j];
                                arr[r]++;
                            }
                        }
                    }
                    if(q>1)
                    {
                        arr[q]++;
                    }
                }
            }

            printf("Case %d: %d = ",p,n);
            //int y,ck;
            for(h=0; arr[prime[h]]>0; h++)
            {
                    printf("%d (%d)",prime[h],arr[prime[h]]);
                    arr[prime[h]]=0;
                    if(arr[prime[h+1]]>0){
                    printf(" * ");}

            }
            cout<<endl;
        }
        p++;
    }

    return 0;
}
//Case 3: 6 = 2 (4) * 3 (2) * 5 (1)
