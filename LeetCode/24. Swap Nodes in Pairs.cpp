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
    ListNode* swapPairs(ListNode* head) {
        ListNode* curr = new ListNode(0);
        curr->next = head;
        while(curr->next != NULL && curr->next->next != NULL){
            ListNode* a = curr->next; ListNode* b = curr->next->next;
            if(curr->next == head) head = b;
            curr->next = b;
            a->next = b->next;
            b->next = a;
            curr = a;
        }
        return head;
    }
};