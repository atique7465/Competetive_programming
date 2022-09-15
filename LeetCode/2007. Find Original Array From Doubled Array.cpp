#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int> &changed) {

        if (changed.size() % 2 != 0) {
            vector<int> emptyVec;
            return emptyVec;
        }

        sort(changed.begin(), changed.end());

        map<int, stack<int>> indexMap;

        for (int i = 0; i < changed.size(); i++) {
            if (indexMap.find(changed[i]) == indexMap.end()) {
                stack<int> st;
                st.push(i);
                indexMap[changed[i]] = st;
            } else {
                indexMap[changed[i]].push(i);
            }
        }

        vector<int> result;
        bool doubled = true;
        for (int i = 0; i < changed.size(); i++) {

            if (changed[i] < 0) {
                continue;
            }

            if (indexMap.find(changed[i] * 2) != indexMap.end() && !indexMap[changed[i] * 2].empty()) {
                int idx = indexMap[changed[i] * 2].top();
                indexMap[changed[i] * 2].pop();
                if (idx == i) {
                    doubled = false;
                    break;
                }
                result.push_back(changed[i]);
                changed[idx] = -1;
            } else {
                doubled = false;
                break;
            }
        }

        if (doubled) {
            return result;
        } else {
            vector<int> emptyVec;
            return emptyVec;
        }
    }
};