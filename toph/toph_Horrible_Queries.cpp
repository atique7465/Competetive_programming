#include<bits/stdc++.h>
using namespace std;
int a[51][100000],arr[51];
int main()
{
    int n,f,i,p,q,j,l,r,k,m,start,end,mid;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&f);
        a[f][arr[f]]=i+1;
        arr[f]++;
    }

   /* for(r=1; r<=n; r++)
    {
        for(j=0; j<=arr[r]; j++)
        {
            cout<<a[r][j]<<" ";
        }
        cout<<endl;
    }*/

    scanf("%d",&q);
    p=1;
    while(p<=q)
    {
        int ind1,ind2;
        scanf("%d%d%d",&l,&r,&k);
        //cout<<l<<r<<k<<endl;
        int count=0;
        for(i=1; i<=50; i++)
        {
            //cout<<arr[i]-1;
            start=0;
            end=arr[i]-1;
            mid=(start+end)/2;
            //cout<<mid;
            while(start<=end)
            {
               // cout<<mid<<start<<end;
                if(a[i][mid]==l)
                {
                    ind1=mid;
                 //   cout<<"k";
                    break;
                }
                else if(a[i][mid]>l)
                {
                    end=mid-1;
                   // cout<<"l";
                    //cout<<end;
                }
                else
                {
                    start=mid+1;
                    //cout<<"m";
                }

                mid=(start+end)/2;
            }
            if (start > end)
            {
                ind1=start;
                //cout<<"n";
                //cout<<ind1;
            }


            start=0;
            end=arr[i]-1;
            mid=(start+end)/2;
            //cout<<mid;
            while(start<=end)
            {
                //cout<<mid<<start<<end;
                if(a[i][mid]==r)
                {
                    ind2=mid;
                  //  cout<<"k";
                    break;
                }
                else if(a[i][mid]>r)
                {
                    end=mid-1;
                    //cout<<"l";
                //    cout<<end;
                }
                else
                {
                    start=mid+1;
                  //  cout<<"m";
                }

                mid=(start+end)/2;
            }
            if (start > end)
            {
                ind2=end;
                //cout<<"n";
                //cout<<ind2;
            }

            if((ind2-ind1+1)>=k)
            {
                count++;
                //out<<"d"<<count;
            }
        }

        printf("%d\n",count);
        p++;
    }
    return 0;
}
