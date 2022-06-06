/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n = 0, m = 0;
        ListNode* theadA = headA;        
        ListNode* theadB = headB;
        while(theadA){
            n++;
            theadA = theadA->next;
        }
        while(theadB){
            m++;
            theadB = theadB->next;
        }
        bool got = false;
        ListNode* ans = new ListNode(0);
        while(n!=m){
            n>m ? headA = headA->next : headB = headB->next;
            n>m ? n-- : m--;
        }
        while(headA){
            if(headA == headB && !got){
                got = true;
                ans = headA;
            }
            else if(got && headA != headB){
                got = false;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return got ? ans : NULL;
    }
};