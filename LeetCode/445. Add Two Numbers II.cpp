#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

    ListNode *resultHead = new ListNode(0);
    ListNode *resultCurr = resultHead;
    int carry = 0;
    ListNode *reverseHead = NULL;

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

        reverse(l1);
        l1 = reverseHead;

        reverse(l2);
        l2 = reverseHead;

        while (l1 != NULL || l2 != NULL || carry != 0) {

            int s = (l1 != NULL ? l1->val : 0) + (l2 != NULL ? l2->val : 0) + carry;
            carry = s / 10;

            resultCurr->next = new ListNode(s % 10);
            resultCurr = resultCurr->next;

            l1 = l1 != NULL ? l1->next : NULL;
            l2 = l2 != NULL ? l2->next : NULL;
        }

        reverse(resultHead->next);
        return reverseHead;
    }

public:
    void reverse(ListNode *l) {

        if (l->next != NULL) {
            reverse(l->next);
        }

        if (l->next == NULL) {
            reverseHead = l;
        } else {
            l->next->next = l;
            l->next = NULL;
        }
    }
};