#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int n,i;
long long int ans=0,c;
int main()
{
    scanf("%d",&n);
    cin>>s1>>s2;
    for(i=0; i<=(n-1)/2; i++)
    {
        c=0;
        if(n%2!=0 && i==(n-1)/2 && s1[i]!=s2[i]){
            ans++;}
        else
        {
            if(s1[i]==s1[n-1-i] && s2[i]==s2[n-1-i])
            {
                continue;
            }
            if(s1[i]==s2[n-1-i] && s2[i]==s1[n-1-i])
            {
                continue;
            }
            else
            {
                if(s1[i]!=s2[i] && s1[i]!=s2[n-1-i]){
                    c++;}
                if(s1[n-1-i]!=s2[i] && s1[n-1-i]!=s2[n-1-i]){
                    c++;}
                if(c==0)
                {
                    if(s1[i]!=s2[i] || s1[n-1-i]!=s2[n-1-i])
                        c++;
                }
                if(c==2)
                {
                    if(s2[i]==s2[n-1-i]){
                        c--;}
                }
            }
            ans=ans+c;
        }
    }
    printf("%lld",ans);
    return 0;
}
