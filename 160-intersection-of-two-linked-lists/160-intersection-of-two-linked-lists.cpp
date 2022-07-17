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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      int a = 1, b = 1;
      ListNode *p = headA;
      ListNode *q = headB;
      while(p->next){
        a++;
        p = p->next;
      }
      while(q->next){
        b++;
        q = q->next;
      }
      int moveA = max(0, a - b);
      int moveB = max(0, b - a);
      p = headA;
      q = headB;
      while(moveA--){
        p = p->next;
      }
      while(moveB--){
        q = q->next;
      }
      while(p != nullptr and q != nullptr){
        if(p == q){
          return p;
        } else {
          p = p->next;
          q = q->next;
        }
      }
      return NULL;
    }
};