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
      ListNode *fast, *slow, *dh = new ListNode(0);
      dh->next = head;
      fast = dh; slow = dh;
      for(int i = 0; i < n; i++)
        fast = fast->next;
      while(fast->next){
        slow = slow->next;
        fast = fast->next;
      }
      slow->next = slow->next->next;
      return dh->next;
    }
};