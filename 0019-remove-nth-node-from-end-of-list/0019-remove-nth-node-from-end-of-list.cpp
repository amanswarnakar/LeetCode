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
      ListNode *dh = new ListNode(0);
      dh->next = head;
      ListNode *fast = dh;
      ListNode *slow = dh;
      while(n--)  fast = fast->next;
      while(fast and fast->next){
        fast = fast->next;
        slow = slow->next;
      }
      slow->next = slow->next->next;
      return dh->next;
    }
};