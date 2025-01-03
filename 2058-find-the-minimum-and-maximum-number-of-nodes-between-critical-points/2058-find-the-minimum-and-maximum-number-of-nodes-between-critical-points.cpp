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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return {-1,-1};
        }
        vector<int>v;
        ListNode* cur=head->next;
        ListNode* prev=head;
        ListNode* nextn=NULL;
        int l=1;
        while(cur->next!=NULL){
            nextn=cur->next;
            l++;
            if(cur->val>prev->val && cur->val>nextn->val){
                v.push_back(l);
            }
            else if(cur->val<prev->val && cur->val<nextn->val){
                v.push_back(l);
            }
            prev=cur;
            cur=nextn;
        }
        if(v.size()<2){
            return {-1,-1};
        }
        int mini=INT_MAX;
        for(int i=1;i<v.size();i++){
            mini=min(mini,(v[i]-v[i-1]));
        }
        int maxi=v[v.size()-1]-v[0];
        return {mini,maxi}; 
    }
};