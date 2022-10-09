#include <bits/stdc++.h>

using namespace std;

class Solution {

    vector<int> freq;

public:
    string robotWithString(string s) {

        freq.resize(26, 0);

        for (char c: s) {
            freq[c - 'a']++;
        }

        stack<char> st;
        string ans = "";
        for (char c: s) {
            st.push(c);
            freq[c - 'a']--;
            while (!st.empty() && st.top() <= currentLow()) {
                ans.push_back(st.top());
                st.pop();
            }
        }

        return ans;
    }

    char currentLow() {
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) return 'a' + i;
        }

        return 'z';
    }
};