#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;

struct data(){
       int art;
       string str;
}input;

int main()
{
   int n,t,m,c;
   vector<int>q;
   cin>>c;
   for(int i=1; i<=c; i++){
             int time=0;
             cin>>n>>t>>m;
             for(int j=1; j<=m; j++){
                    cin>>input.art>>input.str;
                    q.push(input);
             }

             while(!q.empty()){
                       if(q.front().str=="left"){
                        time=time+q.front().irt+t;
                        cout<<time<<endl;
                       }

                      for(int k=1; k<=n; k++){
                           if(q.front().str=="left")
                               time=time+t;
                      }
             }

    return 0;
}
