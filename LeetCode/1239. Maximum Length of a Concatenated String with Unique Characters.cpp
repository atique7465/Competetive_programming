#include <bits/stdc++.h>

using namespace std;

class Solution {
    int len;
public:
    int maxLength(vector<string>& arr) {
        len = arr.size();
        return solve(0, "", arr).size();
    }

    string solve(int i, string s, vector<string>& arr){

        if(i >= len) return s;

        string res = s;

        if(isUnique(s+arr[i])){
            res = solve(i+1, s+arr[i], arr);
        }

        string res2 = solve(i+1, s, arr);

        return res.size() > res2.size() ? res : res2;
    }

    bool isUnique(string str){

        int freq[27];
        memset(freq, 0, sizeof(freq));

       for(int i = 0; i < str.size(); i++){
           if(freq[str[i] - 'a'] > 0){
               return false;
           }

           freq[str[i] - 'a']++;
       }

       return true;
    }
};