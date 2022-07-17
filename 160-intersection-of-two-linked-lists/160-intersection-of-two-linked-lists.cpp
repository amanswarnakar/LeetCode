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
//       int a = 1, b = 1;
//       ListNode *p = headA;
//       ListNode *q = headB;
//       while(p->next){
//         a++;
//         p = p->next;
//       }
//       while(q->next){
//         b++;
//         q = q->next;
//       }
// //       if(p != q){
// //         return NULL;
// //       }
//       int moveA = max(0, a - b);
//       int moveB = max(0, b - a);
//       p = headA;
//       q = headB;
      
//       while(moveA--){
//         p = p->next;
//       }
//       while(moveB--){
//         q = q->next;
//       }
// //       while(p != q){
// //         p = p->next;
// //         q = q->next;
// //       }
// //       return p;  
//       while(p != nullptr and q != nullptr){
//         if(p == q){
//           return p;
//         } else {
//           p = p->next;
//           q = q->next;
//         }
//       }
//       return NULL;
      
      if(headA == nullptr or headB == nullptr) return nullptr;
      ListNode *a = headA;
      ListNode *b = headB;
      while(a != b){
        a = (a == nullptr) ? headB : a->next;
        b = (b == nullptr) ? headA : b->next;
      }
      return a;
    }
};