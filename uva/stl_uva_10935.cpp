#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    while(cin>>n&&n){
    vector<int>v;
    for(i=1; i<=n; i++){
        v.push_back(i);
    }

   cout<<"Discarded cards:";
   for(j=0; j<n-1; j+=2){
       cout<<" "<<v[j];
       if(n<=v.size()&&j!=n-2){
       cout<<",";
       int x=v[j+1];
       v.push_back(x);
       }
       n++;
   }

     int y=v.size();
     cout<<endl<<"Remaining card: "<<v[y-1]<<endl;
    }
    return 0;
}
