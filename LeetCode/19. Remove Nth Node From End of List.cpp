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

class Solution_Length_Calc {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int size = 0;
        ListNode *curr = head;
        while (curr != nullptr) {
            curr = curr->next;
            size++;
        }

        int pos = 0;
        curr = head;
        ListNode *prev = head;
        while (curr != nullptr) {
            pos++;
            if (pos == size - n + 1) {
                break;
            }
            prev = curr;
            curr = curr->next;
        }

        if (curr == head) {
            head = curr->next;
        } else {
            prev->next = curr->next;
        }

        return head;
    }
};

class Solution_2_pointer {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* curr = head;
        ListNode* del = head;
        ListNode* prev = head;
        int currIndex = 0;
        int delIndex = 1;
        while(curr != nullptr){
            currIndex++;
            if(currIndex - delIndex >= n){
                delIndex++;
                prev = del;
                del = del->next;
            }
            curr=curr->next;
        }

        if(del == head){
            head = head->next;
        }else{
            prev->next = del->next;
        }

        return head;
    }
};