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
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

        ListNode *resultHead = NULL;
        ListNode *resultCurr = resultHead;
        int carry = 0;
        while(l1 != NULL || l2 != NULL) {

            int s = (l1 != NULL ? l1->val : 0) + (l2 != NULL ? l2->val : 0) + carry;
            carry = 0;

            int val = s % 10;
            carry = s >= 10 ? 1 : 0;

            ListNode *newNode = new ListNode(val);
            if(resultCurr == NULL){
                resultHead = resultCurr = newNode;
            }else{
                resultCurr->next = newNode;
                resultCurr = newNode;
            }

            if(l1 != NULL){
                l1 = l1->next;
            }

            if(l2 != NULL){
                l2 = l2->next;
            }
        }

        if(carry > 0){
            resultCurr->next = new ListNode(carry);
        }

        return resultHead;
    }
};