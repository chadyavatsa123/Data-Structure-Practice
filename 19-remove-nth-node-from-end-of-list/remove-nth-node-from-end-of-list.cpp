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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        int m=cnt-n;
        if(m==0){
            ListNode* deletenode=head;
            head= head->next;
            deletenode->next=NULL;
            return head;
        }
        ListNode* prev=head;
        while(prev!=NULL){
            m--;
            if(m==0)
            break;
            prev=prev->next;
        }
        ListNode* deletenode=prev->next;
        prev->next=deletenode->next;
        deletenode->next=NULL;
        return head;

    }
};