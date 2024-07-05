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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* dummy = new ListNode(-1); 
        ListNode* tail = dummy; 
        
        ListNode* prev = head;
        ListNode* cur = head->next;
        
        while (cur != nullptr) {
            if (prev->val != cur->val) {
                if (cur->next == nullptr || cur->next->val != cur->val) {
                    tail->next = new ListNode(cur->val);
                    tail = tail->next;
                }
            }
            prev = cur;
            cur = cur->next;
        }
        
        
        if (head->val != head->next->val) {
            ListNode* newNode = new ListNode(head->val);
            newNode->next = dummy->next;
            dummy->next = newNode;
        }
        
        ListNode* newHead = dummy->next;
        delete dummy; 
        return newHead;
    }
};
