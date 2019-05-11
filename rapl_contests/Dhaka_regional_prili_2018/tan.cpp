
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int ts;
    cin>>ts;
    long long int e=1;
    while(e<=ts)
    {
    long long int p=0,r=1,i,j,ln;
    string s,t;
    cin>>s;
    ln=s.size();
    for(i=0;i<ln;i++)
    {
        if(s[i]=='W')
        {
           t[p]=i;
           p++;
        }
    }
    for(j=0;j<p;j++)
    {
        if(t[j]==0||t[j]-'0'==(ln-1))
            r=r*2;
        else
        {
            if(s[j-1]==s[j+1])
            r=r*2;
            else if(s[j-1]!=s[j+1])
                r=r*1;
            if(s[j-1]=='W'||s[j+1]=='W')
                r=r*1;

        }
    }
     cout<<"Case "<<e<<": "<<r<<endl;
     e++;
    }
    return 0;
}
