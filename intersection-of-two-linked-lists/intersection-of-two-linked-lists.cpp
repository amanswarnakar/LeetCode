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
    ListNode *getIntersectionNode(ListNode *ha, ListNode *hb) {
      if(!ha or !hb) return nullptr;
      ListNode *a = ha, *b = hb;
      while(a != b){
        a = a == NULL ? hb : a->next;
        b = b == NULL ? ha : b->next;
      }
      return a;
    }
};