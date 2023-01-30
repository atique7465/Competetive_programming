class Solution {
public:
    int tribonacci(int n) {
        int t_0 = 0, t_1 = 1, t_2 = 1;
        if(n == 0) return 0;
        if(n <= 2) return 1;
        n -= 2;
        int c = 0;
        while(n--){
           c = t_0 + t_1 + t_2;
           t_0 = t_1; t_1 = t_2; t_2 = c; 
        }

        return c;
    }
};