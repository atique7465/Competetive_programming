#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Slow Fast 2P <br>
 * T->O(n/2)
 */
class Solution {
public:
    ListNode *deleteMiddle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        if (slow == head) return head->next;

        prev->next = slow->next;
        return head;
    }
};