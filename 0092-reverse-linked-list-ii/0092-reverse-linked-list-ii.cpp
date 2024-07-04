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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL or head->next==NULL or left==right){
            return head;
        }
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* temp=dummy;
        
        while(left>1){
            temp=temp->next;
            left--;
            right--;
        }
        ListNode* prev=temp;
        ListNode* cur=temp->next;
        ListNode* nextnode=NULL;
        while(right>0){
            nextnode=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nextnode;
            right--;
        }
        temp->next->next=cur;
        temp->next=prev;
        return dummy->next;
    }
};