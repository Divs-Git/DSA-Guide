// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

// 1.
class Solution {
public:
int getLen(ListNode* head) {
  ListNode* temp = head;
  int cnt = 0;
  while(temp != NULL) {
    cnt++;
    temp = temp->next;
  }
  return cnt;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      if(head == NULL) {
        return NULL;
      }
      int len = getLen(head);
      int traverseLen = len - n;
      ListNode* temp = head;
      ListNode* prev = NULL;
      if(n > len) {
        return head;
      }
      if(n == len) {
        
        head = head ->next;
        delete temp;
        return head;
      }
      
      for(int i = 1 ; i < traverseLen ; i++) {
        prev = temp;
        temp = temp->next;
      }
      if(temp -> next == NULL) {
        prev -> next = NULL;
        delete temp;
        return head;
      }
      temp->next = temp -> next -> next;
      return head;
    }
};

// 2.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* first = dummy;
        ListNode* sec = dummy;

        for(int i = 0 ; i <= n ; i++) {
          first = first -> next;
        }

        while(first != NULL) {
          first = first -> next;
          sec = sec -> next;
        }

        ListNode* temp = sec -> next;
        sec->next = sec->next->next;
        delete temp;

        return dummy->next;
    }
};