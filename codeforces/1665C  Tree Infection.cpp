/**
 *@author atiQue
 *@since 5/6/2022 2:39 PM
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> getProcessedVector();

int t, n, x;

int main() {
    cin >> t;
    while (t--) {
        vector<int> vector1 = getProcessedVector();
        priority_queue<int> pq;

        int ln = vector1.size();
        int totalSec = ln;
        for (int i = 0; i < ln; i++) {
            int v = vector1[i] - i - 1;
            if (v > 0) {
                pq.push(v);
            }
        }

        while (!pq.empty()) {
            priority_queue<int> pq2;
            int injectOne = true;
            int top = pq.top();
            pq.pop();
            top--;
            if (top > 0) {
                top--;
                injectOne = false;
            }
            if (top > 0) {
                pq2.push(top);
            }

            while (!pq.empty()) {
                top = pq.top();
                pq.pop();

                top--;
                if (injectOne) {
                    top--;
                    injectOne = false;
                }

                if (top > 0) {
                    pq2.push(top);
                }
            }

            totalSec++;
            pq = pq2;
        }

        cout << totalSec << endl;
    }
}

vector<int> getProcessedVector() {
    cin >> n;
    n--;

    map<int, int> map;

    while (n--) {
        cin >> x;
        if (map.count(x) == 0) {
            map[x] = 1;
        } else {
            map[x]++;
        }
    }

    vector<int> vector;
    vector.push_back(1);
    for (auto const &[k, v]: map) {
        vector.push_back(v);
    }

    sort(vector.begin(), vector.end());

    return vector;
}
