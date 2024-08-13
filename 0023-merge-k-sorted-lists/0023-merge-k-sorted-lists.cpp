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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<>>p;
        ListNode* dummy=new ListNode(-1);
        ListNode*current=dummy;
        for(auto l:lists){
            if(l){
                p.push({l->val,l});
            }
        }
        
        while(!p.empty()){
            auto temp=p.top();
             p.pop();
            current->next=temp.second;
            current=current->next;
            if(current->next){
                p.push({current->next->val,current->next});
            }
            
        }
        return dummy->next;
        
    }
};