#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * T -> O(1)
 */
class Solution_02 {
public:
    void deleteNode(ListNode *node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

/**
 * T -> O(n)
 */
class Solution_01 {
public:
    void deleteNode(ListNode *node) {


        while (node->next != NULL) {
            cout << node->val << endl;
            node->val = node->next->val;
            if (node->next->next == NULL) {
                node->next = NULL;
            } else {

                node = node->next;
            }

        }
    }
};