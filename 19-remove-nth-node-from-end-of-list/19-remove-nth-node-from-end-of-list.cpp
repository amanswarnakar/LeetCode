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
      ListNode *dummyHead = new ListNode(-1);
      dummyHead->next = head;
      ListNode *fast = dummyHead;
      ListNode *slow = dummyHead;
      for(int i = 1; i <= n; i++){
        fast = fast->next;
      }
      while(fast->next != nullptr){
        fast = fast->next;
        slow = slow->next;
      }
      slow->next = slow->next->next;
      return dummyHead->next;
    }
};