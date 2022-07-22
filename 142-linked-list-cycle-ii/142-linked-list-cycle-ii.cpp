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
    ListNode *detectCycle(ListNode *head) {
      ListNode *dh = new ListNode(0);
      dh->next = head;
      ListNode *fast = dh->next;
      ListNode *slow = dh->next;
      if(head == nullptr or head->next == nullptr) return nullptr;
      while(fast->next and fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
          slow = dh->next;
          while(slow != fast){
            slow = slow->next;
            fast = fast->next;
          }
          return slow;
        } 
      }
      return nullptr;
    }
};