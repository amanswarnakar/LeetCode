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
    bool hasCycle(ListNode *head) {
      // Two pointer / Floyd Cycle detection
      // TC - o(n)  SC - o(1)
      if(head == nullptr or head->next == nullptr)  return false;
      ListNode *slow = head, *fast = head;
      while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)  return true;
      }
      return false;
      
      
      
      // Set Approach TC - o(nlogn) SC - O(n)
      // unordered_set<ListNode *> s;
      // while(head){
      //   if(s.insert(head).second == false)
      //     return true;
      //   head = head->next;
      // }
      // return false;
    }
};