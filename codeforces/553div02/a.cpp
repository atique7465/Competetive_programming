#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j,sum,a,b;
    vector<int>v;
    char s[60];
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        cin>>s[i];
    }

    for(i=1; i<=n; i++)
    {
        if(n-i+1<4)
            break;
        sum=0;
        for(j=i; j<=i+3; j++)
        {
            // cout<<"gg="<<s[j]<<" ";
            if(j==i)
            {
                a=abs((s[j]-64)-('A'-64));
                if(s[j]>'A')
                    b=abs(('A'-64)+26-(s[j]-64));
                else
                    b=abs((s[j]-64)+26-('A'-64));
                //cout<<a<<" "<<b<<endl;
                sum+=min(a,b);
            }
            else if(j==i+1)
            {
                a=abs((s[j]-64)-('C'-64));
                if(s[j]>'C')
                    b=abs(('C'-64)+26-(s[j]-64));
                else
                    b=abs((s[j]-64)+26-('C'-64));
                //cout<<a<<" "<<b<<endl;
                sum+=min(a,b);
            }
            else if(j==i+2)
            {
                a=abs((s[j]-64)-('T'-64));
                if(s[j]>'T')
                    b=abs(('T'-64)+26-(s[j]-64));
                else
                    b=abs((s[j]-64)+26-('T'-64));
                //cout<<a<<" "<<b<<endl;
                sum+=min(a,b);
            }
            else if(j==i+3)
            {
                a=abs((s[j]-64)-('G'-64));
                if(s[j]>'G')
                    b=abs(('G'-64)+26-(s[j]-64));
                else
                    b=abs((s[j]-64)+26-('G'-64));
               // cout<<a<<" "<<b<<endl;
                sum+=min(a,b);
            }

        }
        v.push_back(sum);
    }
   // cout<<endl;
    //for(int k=0; k<=v.size()-1; k++)
    //    cout<<v[k]<< " ";
   // cout<<endl;
    sort(v.begin(),v.end());
    printf("%d",v[0]);
    return 0;
}
