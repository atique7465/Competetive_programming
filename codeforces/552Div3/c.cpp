#include<bits/stdc++.h>
using namespace std;
int arr[8]= {0,2,1,1,2,3,1,3};
vector<int>v;
int calc(int F,int R,int C)
{
    vector<int>d;
    for(int i=1; i<=7; i++)
    {
        int f=F,r=R,c=C;
        int mx=0;
        for(int j=i; j<=7; j++)
        {
            if(arr[j]==2)
            {
                mx++;
                r--;
            }
            else if(arr[j]==1)
            {
                mx++;
                f--;
            }
            else
            {
                mx++;
                c--;
            }
            if (f<0 || r<0 || c<0)
            {
                mx--;
                d.push_back(mx);
               // cout<<mx<<" ";
                break;
            }
            if(j==7)
            {
                j=0;
            }
        }
    }
    //cout<<endl;
    sort(d.begin(),d.end());
    return d[d.size()-1];
}

int main()
{
    int F,R,C,i,lw=INT_MAX,g=0,kk;
    scanf("%d",&F);
    v.push_back(F/3);
    scanf("%d",&R);
    v.push_back(R/2);
    scanf("%d",&C);
    v.push_back(C/2);
    if(F<3 || R<2 || C<2)
    {
        int res=calc(F,R,C);
        printf("%d",res);
    }

    else if(F>=3 && R>=2 && C>=2)
    {
        sort(v.begin(),v.end());
        int week=v[0];
        //cout<<week<<endl;
        int res=week*7;
        res=res+calc(F-(week*3),R-(week*2),C-(week*2));
        printf("%d",res);
    }
    return 0;
}

