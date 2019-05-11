#define ONLINE_JUDGE 1
#include<bits/stdc++.h>
using namespace std;
int arr[100001];
vector<long long int>v;
int main()
{
    int n,start,end,mid,t,p=1;
    long long int k,sqrti,i;
    for(i=1; i<=100000; i++)
    {
        //cout<<"L";
        k=(i*i)+(i*i*i);
        //cout<<"m";
        /*start=1;
        end=k/2;
        mid=(start+end)/2;
        while(start<=end)
        {
            //cout<<"K";
            if(mid*mid==k)
            {
                v.push_back(i);
                //cout<<mid;
                break;
            }
            else if(mid*mid>=k)
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
            mid=(start+end)/2;
        }*/

        // arr[i]=arr[i]+arr[i-1];
        sqrti=int(sqrt((double)k));
        if(sqrti*sqrti==k)
            v.push_back(i);
    }

    // cout<<endl;
    /*for(i=0; i<v.size(); i++)
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
            end=v.size()-1;
            mid=(start+end)/2;
            while(start<=end)
            {
                //cout<<start<<" "<<end<<" "<<mid<<" ";
                if(v[mid]==n)
                {
                    ck=mid;
                  //    cout<<"ck"<<ck;
                    break;
                }
                else if(v[mid]>n)
                {
                    end=mid-1;
                }
                else
                {
                    start=mid+1;
                }
                mid=(start+end)/2;
            }
            if(start>end)
            {
                ck=mid;
                //cout<<"ck"<<ck;
            }

            //cout<<v[v.size()-1];
            /*if(n>v[v.size()-1])
            {
                cout<<"B";
                if(ck+2==g)
                    printf("I am married now\n");
                else
                    printf("Baba amar ki biye hobe na\n");
            }
            else*/
           // { cout<<"s";
                if(ck+1==g)
                    printf("I am married now\n");
                else
                    printf("Baba amar ki biye hobe na\n");
            }

         p++;
        }

        return 0;
    }
