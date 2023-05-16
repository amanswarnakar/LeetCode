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
    ListNode* swapPairs(ListNode* head) {
      
      // Swapping the values of the nodes
      // TC - O(N)    SC - O(1)
      ListNode *dummyHead = new ListNode(0);
      dummyHead->next = head;
      if(head == nullptr or head->next == nullptr) return head;
      ListNode *prev = dummyHead->next;
      while(prev->next){
        swap(prev->val, prev->next->val);
        prev = prev->next;
        if(prev->next){
          prev = prev->next;
        }
      }
      return dummyHead->next;
    }
};