#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,c=0;
    string s;
    scanf("%d",&n);
    cin>>s;
    for(i=0; i<n-10; i++)
    {
        if(s[i]=='8')
        {
            c++;
        }
    }

    //cout<<c<<" "<<(n-11)/2<<endl;

    if(c <= (n-11)/2)
        printf("NO");
    else
        printf("YES");
    return 0;
}
