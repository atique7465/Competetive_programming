#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int n,i;
long long int ans=0;
int main()
{
    scanf("%d",&n);
    cin>>s1>>s2;
    for(i=0; i<n; i++)
    {
        if(s1[i]==s2[i])
        {
            continue;
        }
        else if(n%2!=0 && i==n/2)
        {
            ans++;
        }
        else
        {
            if(s1[i]==s2[n-1-i] && s2[i]==s1[n-1-i])
            {
                continue;
            }
            else if(s1[i]==s1[n-1-i] && s2[i]==s2[n-1-i])
            {
                continue;
            }
            else if((s1[i]!=s1[n-1-i]&&s1[i]!=s2[n-1-i]) && (s2[i]==s2[n-1-i] || s2[i]==s1[n-1-i]))
            {
                if(s2[i]==s1[n-1-i])
                    s1[i]=s2[n-i-1];
                else if(s2[i]==s2[n-1-i])
                    s1[i]=s1[n-i-1];
                ans++;
            }
            else
            {
                ans++;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
