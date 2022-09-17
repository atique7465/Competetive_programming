#include <bits/stdc++.h>

using namespace std;

struct node {
    int index = -1;
    node *next[26] = {};
    vector<int> list;
};

class CustomTrie {
private:
    node *root;
public:
    CustomTrie();

//    ~CustomTrie(); //could cause TLE

    void insert(string &word, int wordIndex);

    void search(string &word, int wordIndex, vector<vector<int>> &res);

//    void _delete(node *cur);

    bool isPalindrome(string &word, int start, int end);
};

CustomTrie::CustomTrie() {
    root = new node();
}

void CustomTrie::insert(string &word, int wordIndex) {

    node *cur = root;
    for (int i = word.size() - 1; i >= 0; i--) {

        if (cur->next[word[i] - 'a'] == NULL) {
            cur->next[word[i] - 'a'] = new node();
        }

        if (isPalindrome(word, 0, i)) {
            cur->list.push_back(wordIndex);
        }

        cur = cur->next[word[i] - 'a'];
    }

    cur->list.push_back(wordIndex); //cause rest of word is palindrome (as there is no char left)
    cur->index = wordIndex;
}

void CustomTrie::search(string &word, int wordIndex, vector<vector<int>> &res) {

    node *cur = root;

    for (int i = 0; i < word.size(); i++) {

        if (cur->index >= 0 && cur->index != wordIndex && isPalindrome(word, i, word.size() - 1)) {
            res.push_back({wordIndex, cur->index});
        }

        cur = cur->next[word[i] - 'a'];

        if (cur == NULL) {
            return;
        }
    }

    for (int i = 0; i < cur->list.size(); i++) {
        if (wordIndex != cur->list[i]) {
            res.push_back({wordIndex, cur->list[i]});
        }
    }
}

bool CustomTrie::isPalindrome(string &word, int start, int end) {
    while (start < end) {
        if (word[start++] != word[end--]) return false;
    }
    return true;
}

//CustomTrie::~CustomTrie() {
//    _delete(root); //could cause TLE
//}
//
//void CustomTrie::_delete(node *cur) {
//    for (int i = 0; i < 26; i++) {
//        if (cur->next[i] != NULL)
//            _delete(cur->next[i]);
//    }
//    delete (cur);
//}

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string> &words) {

        CustomTrie T;
        for (int i = 0; i < words.size(); i++) {
            T.insert(words[i], i);
        }

        vector<vector<int>> result;

        for (int i = 0; i < words.size(); i++) {
            T.search(words[i], i, result);
        }

        return result;
    }
};

int main() {
    vector<string> words = {"a", "abc", "aba", ""};
    Solution solution;
    vector<vector<int>> res = solution.palindromePairs(words);

    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        if (i != 0) {
            cout << ",";
        }
        cout << "[";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j];
            if (j < res[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
    }
    cout << "]";

    return 0;
}