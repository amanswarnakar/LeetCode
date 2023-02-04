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
      // if(!ha or !hb) return nullptr;
      // ListNode *a = ha, *b = hb;
      // while(a != b){
      //   a = a == NULL ? hb : a->next;
      //   b = b == NULL ? ha : b->next;
      // }
      // return a;
      
      int c = 1, d = 1;
      ListNode *a = ha, *b = hb;
      while(a){
        a = a->next;
        c++;
      }
      while(b){
        b = b->next;
        d++;
      }
      int ma = max(0, c - d), mb = max(0, d - c);
      a = ha;
      b = hb;
      while(ma--){
        a = a->next;
      }
      while(mb--){
        b = b->next;
      }
      while(a != b){
        a = a->next;
        b = b->next;
      }
      return a;
    }
};