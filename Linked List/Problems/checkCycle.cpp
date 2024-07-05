// https://leetcode.com/problems/linked-list-cycle/description/
 
// brute
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*,bool> table;
        ListNode* temp = head;
        while(temp != NULL) {
          if(table[temp] == false) {
            table[temp] = true;
          } else {
            return true;
          }
          temp = temp->next;
        }
        return false;
    }
};

// optimised
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL) {
          fast = fast->next;
          if(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
          }

          if(slow == fast) {
            return true;
          }
        }
        return false;
    }
};

// 2. Detect the  starting node in loop
// https://leetcode.com/problems/linked-list-cycle-ii/description/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
      ListNode* slow = head;
      ListNode* fast = head;
      bool flag = false;

      while(fast!= NULL) {
        fast = fast->next;
        if(fast != NULL) {
          fast = fast->next;
          slow = slow ->next;
        }
        // loop present
        if(slow == fast) {
          flag = true;
          slow = head;
          break;
        }
      }

      if(flag == false) {
        return NULL;
      }

      while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
      }
        return slow;
    }
};

