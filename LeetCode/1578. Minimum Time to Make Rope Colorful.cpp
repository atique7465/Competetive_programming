#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int> &neededTime) {

        int result = 0;

        int len = colors.size();

        int i = 0;
        while (i < len) {

            int time = neededTime[i];
            int mxTime = neededTime[i];
            while (i + 1 < len && colors[i] == colors[i + 1]) {
                time += neededTime[i + 1];
                mxTime = max(mxTime, neededTime[i + 1]);
                i++;
            }

            result += time - mxTime;

            i++;
        }

        return result;
    }
};
