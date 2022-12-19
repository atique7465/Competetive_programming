class Solution {
    int inf = -1;
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = inf, carry = 0, curr;
        for(int i = 0; i < gas.size(); i++){
           curr = carry + gas[i] - cost[i];
           if(curr >= 0) {
              if(start == inf) start = i;
              carry = curr;   
           }else {
              carry = 0;
              start = inf;
           }
        }
        if(carry < 0 || start == inf) return -1;
        for(int i = 0; i < gas.size(); i++){
           if(i==start) break;
           curr = carry + gas[i] - cost[i];
           if(curr >= 0) carry = curr;   
           else return -1;
        }
        return start;
    }
};