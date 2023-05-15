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
    ListNode* swapNodes(ListNode* head, int k) {
      ListNode *dh = new ListNode(0);
      dh->next = head;
      ListNode *c1 = dh->next, *c2 = dh->next;
      int n = 0;
      while(c1){
        c1 = c1->next;
        n++;
      }
      int j = n - k;
      c1 = dh->next;
      for(int i = 0; i < k - 1; i++)
        c1 = c1->next;
      for(int i = 0; i < j; i++)
        c2 = c2->next;
      swap(c1->val, c2->val);
      return dh->next;      
    }
};