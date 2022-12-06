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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return head;
        ListNode *pre, *cur, *move;
        pre=head;
        cur=head->next;
        while(cur && cur->next){
            move=cur->next;
           
            cur->next=move->next;
            move->next=pre->next;
            pre->next=move;
          
            pre=pre->next;
            cur=cur->next;
        }
        return head;
    }
};