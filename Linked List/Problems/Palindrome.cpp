// https://leetcode.com/problems/palindrome-linked-list/description/

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
    ListNode* getMiddle(ListNode* head){
      ListNode* slow = head;
      ListNode* fast = head;
      while(fast->next != NULL) {
        fast =fast->next;
        if(fast->next != NULL) {
          fast = fast->next;
          slow = slow->next;
        }
      }
      return slow;
    }
    ListNode* reverse(ListNode* head) {
      ListNode* prev = NULL;
      ListNode* curr  = head;
      if(curr ==NULL) {
        return prev;
      }

      while(curr != NULL) {
        ListNode* currNext = curr->next;
        curr->next = prev;
        prev = curr;
        curr = currNext;
      }
      return prev;
    }
    bool isPalindrome(ListNode* head) {
      ListNode* middleNode = getMiddle(head);
      ListNode* head2 = middleNode->next;
      middleNode->next = NULL;

      // reverse second half
      head2 = reverse(head2);
      ListNode* temp1 = head;
      ListNode* temp2 = head2;
      while(temp1 != NULL && temp2 !=NULL) {
        if(temp1->val != temp2->val) {
          return false;
        }
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
      }
      return true;
    }
};