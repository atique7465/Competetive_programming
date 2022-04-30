#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    string input;

    cin >> t;

    while (t--) {
        cin >> input;
        int ln = input.length();
        map<char, bool> prevFound;

        int curr_res = 0;
        int total_res = 0;
        for (int i = 0; i < ln; i++) {
            curr_res++;

            if (prevFound.count(input[i]) == 0) {
                prevFound[input[i]] = true;
            } else {
                total_res += curr_res - 2;
                curr_res = 0;
                prevFound.clear();
            }
        }

        cout << total_res + curr_res << endl;
    }

    return 0;
}
