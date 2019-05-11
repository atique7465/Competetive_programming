#include<bits/stdc++.h>
using namespace std;
int arr[27];
int main()
{
    int tp=0,i,k;
    string s;
    cin>>s;
    for(i=0; i<s.size(); i++)
    {
        k=(s[i]-'a')+1;
        if(arr[k]==0)
        {
            tp++;
        }
        arr[k]++;
    }

    /*cout<<tp<<endl;
    for(i=0; i<27; i++)
        cout<<arr[i];*/


    if(tp==1||tp>4)
        printf("No");

    else if(tp==2)
    {
        int ck=0;
        for(i=0; i<27; i++)
        {
            if(arr[i]>0)
            {
                if(arr[i]<2)
                    ck=1;
            }

        }
        if(ck==0)
            printf("Yes");
        else
            printf("No");
    }

    else if(tp==4)
        printf("Yes");

    else if(tp==3){
        int ck=0;
        for(i=0; i<27; i++)
        {
            if(arr[i]>0)
            {
                if(arr[i]>1)
                    ck=1;
            }

        }
        if(ck==1)
            printf("Yes");
        else
            printf("No");
    }

    return 0;
}
