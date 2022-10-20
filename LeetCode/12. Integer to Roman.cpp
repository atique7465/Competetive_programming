#include <bits/stdc++.h>

using namespace std;

class Solution {

    vector<pair<int, string>> symbols = {{1000, "M"},
                                         {900,  "CM"},
                                         {500,  "D"},
                                         {400,  "CD"},
                                         {100,  "C"},
                                         {90,   "XC"},
                                         {50,   "L"},
                                         {40,   "XL"},
                                         {10,   "X"},
                                         {9,    "IX"},
                                         {5,    "V"},
                                         {4,    "IV"},
                                         {1,    "I"}};

public:
    string intToRoman(int num) {

        string result = "";

        int len = symbols.size();
        for (int i = 0; i < len && num > 0; i++) {
            if (num >= symbols[i].first) {
                int cnt = num / symbols[i].first;
                for (int j = 0; j < cnt; j++) {
                    result += symbols[i].second;
                    num -= symbols[i].first;
                }
            }
        }

        return result;
    }
};