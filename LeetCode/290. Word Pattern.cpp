class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> pattMap;
        vector<int> pattV;
        unordered_map<string, int> strMap;
        vector<int> pattS;

        int cnt = 0;
        for(int i = 0; i<pattern.size(); i++){
           if(pattMap.find(pattern[i]) == pattMap.end()) {
              pattMap[pattern[i]] = cnt++;
              pattV.push_back(pattMap[pattern[i]]);
           } else pattV.push_back(pattMap[pattern[i]]);
        }

        cnt = 0;
        int i = 0, j = 0;
        while(i < s.size() && j < s.size()){
            while(j < s.size() && s[j] != ' ') j++;
            string curr = s.substr(i, j - i);
            if(strMap.find(curr) == strMap.end()) {
              strMap[curr] = cnt++;
              pattS.push_back(strMap[curr]);
           } else pattS.push_back(strMap[curr]);
           j++; i = j;
        }

        for(int i = 0; i < pattV.size(); i++) cout<<pattV[i]<<" ";
        cout<<endl;

        for(int i = 0; i < pattS.size(); i++) cout<<pattS[i]<<" ";
        cout<<endl;

        return pattV == pattS;
    }
};