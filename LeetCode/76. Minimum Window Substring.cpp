#include <bits/stdc++.h>

using namespace std;

/**
 * 01. increase end pointer and decrease need counter if we found a char that is needed to match
 * 02. if no other char needed to match update the min range
 * 03. its time to move forward start pointer and track if we skip any char which is needed
 */
class Solution {
public:
    string minWindow(string s, string t) {

        int need = t.size(), sLen = s.size();
        vector<int> freq(128, 0);
        for (char c: t) freq[c]++;

        int minRange = INT_MAX, minStart = 0, start = 0, end = 0;
        while (end < sLen) {
            freq[s[end]]--;
            if (freq[s[end]] >= 0) need--;

            while (need == 0) {
                if (end - start + 1 < minRange) minRange = end - (minStart = start) + 1;

                freq[s[start]]++;
                if (freq[s[start]] > 0) need++;
                start++;
            }

            end++;
        }

        return minRange == INT_MAX ? "" : s.substr(minStart, minRange);
    }
};

class Solution_01 {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> tFreq;
        unordered_map<char, int> sFreq;

        int tLen = t.size();
        for (int i = 0; i < tLen; i++) tFreq[t[i]]++;

        int sLen = s.size(), totalItem = tFreq.size(), start = 0, end = 0, items = 0, minRange = INT_MAX, minStart = 0;
        string result = "";
        while (end < sLen) {
            char c = s[end];
            if (tFreq.find(c) != tFreq.end()) {
                sFreq[c]++;
                if (sFreq[c] == tFreq[c]) items++;

                if (items == totalItem) {
                    while (start <= end) {
                        c = s[start];
                        if (tFreq.find(c) != tFreq.end()) {
                            if (sFreq[c] > tFreq[c]) {
                                sFreq[c]--;
                            } else {
                                break;
                            }
                        }
                        start++;
                    }
                    if (end - start + 1 < minRange) minRange = end - (minStart = start) + 1;
                }
            }
            end++;
        }

        return minRange == INT_MAX ? "" : s.substr(minStart, minRange);
    }
};