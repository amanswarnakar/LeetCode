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
    ListNode* deleteMiddle(ListNode* head) {
      if(!head or !head->next) return nullptr;
      ListNode *fast, *slow, *prev, *dh = new ListNode(0);
      dh->next = head;
      fast = slow = head;
      while(fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next;
        if(fast->next)  fast = fast->next;
      }
      prev->next = slow->next;
      return dh->next;
    }
};