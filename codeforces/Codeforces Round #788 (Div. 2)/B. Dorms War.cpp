/**
 *@author atiQue
 *@since 5/6/2022 8:03 PM
*/

#include <bits/stdc++.h>

using namespace std;


int main() {
    int t, n, k;
    string str;
    char ch;

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        cin >> str;
        scanf("%d", &k);
        set<char> charSet;
        while (k--) {
            cin>>ch;
            charSet.insert(ch);
        }

        int ln = str.length();
        for (int i = 0; i < ln; i++) {
            if (charSet.find(str[i]) != charSet.end()) {
                str[i] = '1';
            }
        }


        int max = 0;
        int i = ln - 1;

        while (i >= 0) {

            int cnt = 0;
            if (str[i] == '1') {
                i--;
                while (i >= 0) {
                    cnt++;
                    if (str[i] == '1') {
                        break;
                    }
                    i--;
                }
            } else {
                i--;
            }

            if (max < cnt) {
                max = cnt;
            }
        }

        printf("%d\n", max);
    }

    return 0;
}