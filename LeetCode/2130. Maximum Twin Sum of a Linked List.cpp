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
    int pairSum(ListNode* head) {
        vector<int> v;
        while(head != NULL) {
            v.push_back(head->val);
            head = head->next;
        }

        int s = 0, e = v.size() - 1, res = 0;
        while(s < e) res = max(res, v[s++] + v[e--]);

        return res;
    }
};