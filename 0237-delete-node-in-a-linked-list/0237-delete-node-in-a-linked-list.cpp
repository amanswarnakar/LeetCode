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
    void deleteNode(ListNode* node) {
      ListNode *temp = node->next;
      node->val = node->next->val;
      node->next = node->next->next;
      delete temp;
      
      // ListNode *next = node->next;
      // node->val = next->val;
      // node->next = next->next;
      // delete next;
      
      
      // ListNode *next = node->next;
      // *node = *next;
      // delete next;
    }
};