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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int sum = ((l1 -> val) + (l2 -> val));
        int carry = sum > 9?1:0;

        ListNode* soln = new ListNode(sum%10);
        ListNode* tmp = soln;

        l1 = l1 -> next;
        l2 = l2 -> next;

        while(l1 != NULL && l2 != NULL){
            sum = (l1 -> val + l2 -> val + carry);
            carry = sum > 9?1:0;

            tmp -> next = new ListNode(sum%10);
            
            tmp = tmp -> next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }

        while(l1 != NULL){
            sum = l1 -> val + carry;
            carry = sum > 9?1:0;
            tmp -> next = new ListNode(sum%10);
            tmp = tmp -> next;
            l1 = l1 -> next;
        }

        while(l2 != NULL){
            sum = l2 -> val + carry;
            carry = sum > 9?1:0;
            tmp -> next = new ListNode(sum%10);
            tmp = tmp -> next;
            l2 = l2 -> next;
        }
        if(carry) tmp -> next = new ListNode(carry);
        return soln;
    }
};