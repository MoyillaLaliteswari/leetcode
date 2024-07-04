/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     Node * removel(Node* head,int ele){
//         if(head==NULL) return head;
//         if(head->val==ele){
//             Node* temp=head;
//             head=head->next;
//             free(temp);
//             return head;
//         }
//         Node* temp=head;
//         Node* prev=NULL;
//         while(temp!=NULL){
//             if(temp->data==ele){
//                 prev->next=prev->next->next;
//                 free(temp);
//                 break;
//             }
//             prev=temp;
//             temp=temp->next;
//         }
//         return head;
//     }
//     void deleteNode(ListNode* node) {
//        removel(head,node)
//        return ; 
        
//     }
// };
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == NULL || node->next == NULL) return;
        node->val = node->next->val;
        ListNode* temp = node->next; 
        node->next = node->next->next;
        delete temp;
    }
};
