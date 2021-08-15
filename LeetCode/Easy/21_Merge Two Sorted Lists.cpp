//----------------------------------------------------------------------------------
// [ 21. Merge Two Sorted Lists ] https://leetcode.com/problems/merge-two-sorted-lists/
//----------------------------------------------------------------------------------

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *cur, *next;
        if (!l1) return l2;
        if (!l2) return l1;
        
        if (l1->val > l2->val) {
            ListNode *tmp = l2;
            l2 = l1; 
            l1 = tmp;
        }
        
        cur = l1; 
        next = cur->next;

        while (next) {
            while (l2->val <= next->val) {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
                cur->next = next;
                if (!l2) return l1;
            }
            cur = cur->next;
            next = next->next;
        }

        while (l2) {
            cur->next = l2;
            cur = cur->next;
            l2 = l2->next;
            cur->next = next;
        }

        return l1;
    }
};