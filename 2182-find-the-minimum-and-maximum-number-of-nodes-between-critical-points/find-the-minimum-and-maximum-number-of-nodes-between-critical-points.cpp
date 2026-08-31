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
        if(head->next==NULL || head->next->next==NULL)
        return {-1,-1};
       ListNode* temp=head;
       ListNode* curr=head->next;
        int pos=2;
       ListNode* nxt=curr->next;
        vector<int>res;
        while(curr->next!=NULL){
            if(curr->val < temp->val && curr->val < nxt->val){
                res.push_back(pos);
            }
            if(curr->val > temp->val && curr->val > nxt->val){
                res.push_back(pos);
            }
            temp=curr;
            curr=nxt;
            nxt=nxt->next;
            pos++;
        }
        if(res.size()<2)return {-1,-1};
    int mx=INT_MIN;
 
    int mn=INT_MAX;
  
    for(auto it:res){
        if(it>mx)
            mx=it;
        if(it<mn)    
            mn=it;     
    }
    int mindistance=INT_MAX;
  for(int i=0;i<res.size()-1;i++)
   mindistance=min(mindistance,res[i+1]-res[i]);
   int maxdistance=mx-mn;
    return {mindistance,maxdistance};

    }
};