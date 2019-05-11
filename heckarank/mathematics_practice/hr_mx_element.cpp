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
int main()
{
    int n,tp,v;
    cin>>n;
    stack<int> s1,s2;

    s2.push(0);

    for(int i=1; i<=n; i++){
      cin>>tp;

      if(tp==1){
        cin>>v;
        s1.push(v);
            if(v>=s2.top()){
                s2.push(v);
                }
                }

      else if(tp==2){
             if(s1.top()==s2.top()){
                s2.pop();}
             s1.pop();
             }

      else if(tp==3){
            cout<<s2.top()<<endl;
      }

}
    return 0;
}
