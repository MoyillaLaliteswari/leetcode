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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL) return NULL;
        int len=0;
        ListNode* temp=head;
        
        while(temp!=NULL){
            len=len+1;
            temp=temp->next;
        }
        int k=len/2;
        temp=head;
        while(k!=1){
            temp=temp->next;
            k--;
        }
        temp->next=temp->next->next;
        return head;
    }
};