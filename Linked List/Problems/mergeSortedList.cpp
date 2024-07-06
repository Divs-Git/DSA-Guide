// https://leetcode.com/problems/merge-two-sorted-lists/description/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2 ==NULL) {
          return NULL;
        }

        if(list1 == NULL && list2 != NULL) {
          return list2;
        }

        if(list1 != NULL && list2 == NULL) {
          return list1;
        }

        ListNode* t1 = list1;
        ListNode* t2 = list2;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr  = dummy;

        while(t1 != NULL && t2 != NULL) {
          if(t1->val < t2 ->val ){
            curr -> next = t1;
            curr = t1;
            t1 = t1 -> next;
          } else {
            curr -> next = t2;
            curr = t2;
            t2 = t2 -> next;
          }
        }

        if(t1) curr -> next = t1;
        if(t2) curr->next = t2;

        return dummy -> next;
    }
};