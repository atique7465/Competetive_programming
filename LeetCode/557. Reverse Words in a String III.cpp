class Solution {
public:
    string reverseWords(string s) {
        int ln = s.size();
        int i = 0, j = 0;
        while (i < ln && j < ln) {
            while (j < ln && s[j] != ' ') {
                j++;
            }
            reverse(s, i, j - 1);
            j++;
            i = j;
        }
        return s;
    }

public:
    void reverse(string &s, int i, int j) {
        while (i < j) {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
        }
    }
};