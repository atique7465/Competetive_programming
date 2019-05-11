#include<bits/stdc++.h>
using namespace std;
string ch;
int arr[100000];
int main()
{
    int t,c=1;
    scanf("%d",&t);
    while(c<=t)
    {
        int count=0,n;
        cin>>ch;
        scanf("%d",&n);
        int ln=ch.size();
        for(int i=0; i<ln; i++)
        {
            int p=ch[i]-48;
            if(arr[p]>0)
            {
                count++;
            }
            arr[p]++;
        }
        for(int i=0; i<ln; i++)
        {
            int q=ch[i]-48;
            arr[q]=0;
        }
        if(n>=count)
            printf("YES\n");
        else
            printf("NO\n");
        c++;
    }
    return 0;
}

