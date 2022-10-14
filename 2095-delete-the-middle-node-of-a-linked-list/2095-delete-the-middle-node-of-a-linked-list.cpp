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
    ListNode* deleteMiddle(ListNode* h) {
        if(!h or !h->next) return NULL;
        
        ListNode* s = h,*f = h;
        ListNode* pre = NULL;
        
        while(f and f->next){
            pre = s;
            f = f->next->next;
            s = s->next;
        }
        
        ListNode* t = s;
        
        pre->next = pre->next->next;
        
        delete(t);
        
        return h;
        
    }
};