#include <bits/stdc++.h>

using namespace std;


class Solution {

    int inf = 999999;

public:
    string pushDominoes(string dominoes) {
        int len = dominoes.size();
        map<int, pair<int, int>> mp;

        int lastRight = inf;
        for (int i = 0; i < len; i++) {

            if (dominoes[i] == 'R') {
                lastRight = i;
            }

            mp[i] = make_pair(lastRight, inf);

            if (dominoes[i] == 'L') {
                lastRight = inf;
            }
        }

        int lastLeft = inf;
        for (int i = len - 1; i >= 0; i--) {

            if (dominoes[i] == 'L') {
                lastLeft = i;
            }

            mp[i].second = lastLeft;

            if (dominoes[i] == 'R') {
                lastLeft = inf;
            }
        }

        for (auto const &[k, v]: mp) {
            int right = (v.first == inf) ? inf : (k - v.first);
            int left = (v.second == inf) ? inf : (v.second - k);
            if (left - right > 0) {
                dominoes[k] = 'R';
            } else if (left - right < 0) {
                dominoes[k] = 'L';
            } else {
                dominoes[k] = '.';
            }
        }

        return dominoes;
    }
};

int main() {
    Solution s;
    cout << s.pushDominoes(".L.R...LR..L..");
    return 0;
}