// Brute -> O(2n)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp  = head;
        int cnt = 0;
        while(temp != NULL) {
          cnt++;
          temp = temp->next;
        }
        
        temp = head;
        for(int i = 1 ; i < (cnt/2) + 1 ; i++) {
          temp = temp->next;
        } 
        return temp;
    }
};

// O(n)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) {
          slow = slow->next;
          fast = fast->next->next;
        }
        return slow;
    }
};