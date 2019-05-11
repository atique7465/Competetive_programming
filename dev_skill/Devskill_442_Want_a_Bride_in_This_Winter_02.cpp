#include<bits/stdc++.h>
using namespace std;
//int arr[100001];
vector<long long int>v;
int main()
{
    int n,t,p=1;
    long long int k,sqrti,i,start,en,mid;
    unsigned long long int kl;
    for(i=1; i<=100000; i++)
    {
        k=(i*i)+(i*i*i);
        start=1;
        en=k/2;
        mid=(start+en)/2;
        while(start<=en)
        {
            kl=mid*mid;
            if(kl==k)
            {
                v.push_back(i);
                break;
            }
            else if(kl>k)
                en=mid-1;

            else
                start=mid+1;


            mid=(start+en)/2;
        }

        // arr[i]=arr[i]+arr[i-1];
        /*sqrti=int(sqrt((double)k));
        if(sqrti*sqrti==k)
            v.push_back(i);
            */
    }

   /* cout<<v.size()<<" "<<i<<endl;
    for(i=0; i<v.size(); i++)
    {
      cout<<v[i]<<" ";
    }*/

    scanf("%d",&t);
    while(p<=t)
    {
        int ck,g;
        scanf("%d%d",&n,&g);
        if(n<v[0])
            printf("Baba amar ki biye hobe na\n");
        else
        {
            start=0;
            en=v.size()-1;
            mid=(start+en)/2;
            while(start<=en)
            {
                if(v[mid]==n)
                {
                    ck=mid;
                    break;
                }
                else if(v[mid]>n)
                {
                    en=mid-1;
                }
                else
                {
                    start=mid+1;
                }
                mid=(start+en)/2;
            }
            if(start>en)
            {
                ck=mid;
            }


                if(ck+1==g)
                    printf("I am married now\n");
                else
                    printf("Baba amar ki biye hobe na\n");
            }

         p++;
        }

        return 0;
    }
