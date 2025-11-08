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
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        while(l1!=NULL &&  l2!=NULL){
            if(l1->val >l2->val){
                temp->next = l2;
                temp =l2;
                l2= l2->next;
            }
            else{
                temp->next = l1;
                temp =l1;
                l1= l1->next;
            }
        }
        if(l1){
            temp->next = l1;
        }
        if(l2){
            temp->next = l2;
        }
        return ans->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        ListNode* head = lists[0];
        for(int i=1;i<lists.size();i++){
            head = merge(head, lists[i]);
        }
        return head;
    }
};
