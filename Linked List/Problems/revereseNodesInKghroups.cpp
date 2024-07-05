// https://leetcode.com/problems/reverse-nodes-in-k-group/description/
class Solution {
public:
    int getLength(ListNode* head) {
      ListNode* temp = head;
      int cnt = 0;
      while(temp != NULL) {
        cnt++;
        temp = temp->next;
      }
      return cnt;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
      if(k == 0) {
        return head;
      }
        if(getLength(head) < k) {
          return head;
        }

        if(head == NULL) {
          return NULL;
        }

        if(head -> next == NULL) {
          return head;
        }

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* currNext = curr->next;
        int pos = 1;
        while(pos <= k) {
          currNext = curr->next;
          curr -> next = prev;
          prev = curr;
          curr = currNext;
          pos++;
        }
        ListNode* recAns = NULL;
        if(currNext != NULL) {
           recAns = reverseKGroup(currNext,k);
           head->next = recAns;
        }
        return prev;
    }
};