//----------------------------------------------------------------------------------
// [ 2. Add Two Numbers ] https://leetcode.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* pBegin = new ListNode(), *pNode = pBegin;
        int up = 0, val;
        while (true) {
            val = 0;
            if (l1) {
                val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                val += l2->val;
                l2 = l2->next;
            }   
            if (up) val += up--;
            if (val > 9 && ++up) val -= 10;
            pNode->val = val;
            if (!l1 && !l2) break;
            pNode = (pNode->next = new ListNode());
        }
        if (up) pNode->next = new ListNode(1);
        return pBegin;
    }
};