#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {

        string numberStr = "";
        bool positive = true;
        bool signFound = false;
        bool numberFound = false;
        int sLen = s.size();
        for (int i = 0; i < sLen; i++) {
            char c = s[i];
            if (!numberFound && c != ' ' && c != '+' && c != '-' && (c < '0' || c > '9')) {
                return 0;
            }
            if (signFound && !numberFound && (c < '0' || c > '9')) {
                return 0;
            }
            if (numberFound && (c < '0' || c > '9')) {
                break;
            }

            if (c == '-' || c == '+') positive = (c == '-') ? false : true, signFound = true;

            if (c >= '0' && c <= '9') {
                numberStr.push_back(c);
                numberFound = true;
            }
        }


        int i = 0;
        while (i < numberStr.size() && numberStr[i] == '0') i++;
        numberStr = numberStr.substr(i, numberStr.size() - i);

        if (numberStr.size() > 10) return positive ? INT_MAX : INT_MIN;

        long long int calcNumber = 0, base = 1;
        for (int i = numberStr.size() - 1; i >= 0; i--) {
            calcNumber += (numberStr[i] - '0') * base;
            base *= 10;
        }

        return positive ? (calcNumber > INT_MAX ? INT_MAX : calcNumber) : (-1 * calcNumber < INT_MIN ? INT_MIN : (-1 *
                                                                                                                  calcNumber));
    }
};