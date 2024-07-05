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
    ListNode* reversell(ListNode* temp){
        ListNode* nextnn=NULL;
        ListNode* prev=NULL;
        while(temp!=NULL){
            nextnn=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nextnn;
        }
        return prev;
    }
    ListNode* getkNode(ListNode* temp,int k){
        k-=1;
        while(temp!=NULL && k>0){
            temp=temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevLast=NULL;
        while(temp!=NULL){
            ListNode* kNode=getkNode(temp,k);
            if(kNode == NULL){
                if(prevLast) prevLast->next=temp;
                break;
            }
            ListNode* nextn=kNode->next;
            kNode->next=NULL;
            reversell(temp);
            if(temp==head){
                head=kNode;
            }
            else{
                prevLast->next=kNode;
            }
            prevLast=temp;
            temp=nextn;
        }
        return head;
    }
};