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
    
ListNode* start;
int matchCount = 0;
    
public:
    bool isPalindrome(ListNode* head) {
        int ln = 0;
        ListNode* curr = head;
        while(curr != nullptr){
            ln++;
            curr = curr->next;
        }
        
        start = head;
        
        findMatchCount(head);
        
        if(matchCount == ln){
            return true;
        }else{
            return false;
        }
    }
    
public:
    void findMatchCount(ListNode* head) {
        if(head == nullptr){
            return;
        }
        
        findMatchCount(head->next);
        
        if(start->val == head->val){
            matchCount++;
        }  
        
        start = start->next;
    }
};