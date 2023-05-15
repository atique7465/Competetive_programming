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
    ListNode* swapNodes(ListNode* head, int k) {

        ListNode* a = head; ListNode* b = head;

        int i = k - 1;
        while(i--) a = a->next;

        ListNode* curr = a;
        while(curr->next != NULL){
            b = b->next; curr = curr->next;
        }

        int tmp = b->val;
        b->val = a->val;
        a->val = tmp;
        
        return head;
    }
};