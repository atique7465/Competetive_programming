#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main()
{
    int x1,x2,x3,x4,a,b,c;
    scanf("%d",&x1);
    scanf("%d",&x2);
    scanf("%d",&x3);
    scanf("%d",&x4);
    v.push_back(0);
    v.push_back(x1);
    v.push_back(x2);
    v.push_back(x3);
    v.push_back(x4);
    sort(v.begin(),v.end());

    a=v[4]-v[2];
    b=v[4]-v[3];
    c=v[4]-v[1];

    printf("%d %d %d",a,b,c);

    return 0;
}
