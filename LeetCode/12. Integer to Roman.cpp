#include <bits/stdc++.h>

using namespace std;

class Solution {

    vector<pair<int, char>> symbols = {{1000, 'M'},
                                       {500,  'D'},
                                       {100,  'C'},
                                       {50,   'L'},
                                       {10,   'X'},
                                       {5,    'V'},
                                       {1,    'I'}};
    unordered_map<int, string> mp = {{4,   "IV"},
                                     {9,   "IX"},
                                     {40,  "XL"},
                                     {90,  "XC"},
                                     {400, "CD"},
                                     {900, "CM"}};

public:
    string intToRoman(int num) {

        vector<int> parts;

        int base = 1;
        while (num > 0) {
            int digit = num % 10;
            parts.push_back(digit * base);
            num /= 10;
            base *= 10;
        }

        string result = "";
        int len = parts.size();
        for (int i = len - 1; i >= 0; i--) {
            if (parts[i] != 0) {
                result += getRoman(parts[i]);
            }
        }

        return result;
    }

    string getRoman(int part) {

        string result = (mp.find(part) != mp.end()) ? mp[part] : "";

        if (result != "") {
            return result;
        }

        int len = symbols.size();
        for (int i = 0; i < len && part > 0; i++) {
            if (part >= symbols[i].first) {
                int cnt = part / symbols[i].first;
                for (int j = 0; j < cnt; j++) {
                    result.push_back(symbols[i].second);
                    part -= symbols[i].first;
                }
            }
        }

        return result;
    }
};