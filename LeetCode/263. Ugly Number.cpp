class Solution {
public:
    bool isUgly(int n){
        
      if(n<=0) return false;
      vector<int> list = {2,3,5};
      for(int i=0; i<list.size(); i++){
        
             while(n%list[i]==0){
                 n/=list[i];
             }
         
      }
      return n==1;
    }
};