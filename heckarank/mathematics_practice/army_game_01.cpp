#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,c;
    scanf("%d%d",&n,&m);
    c=(n+n%2)*(m+m%2)/4;
    cout<<c;
return 0;}
