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
    ListNode* reverseKGroup(ListNode* head, int k) {
      int length = 0;
      ListNode *dh = new ListNode(0);
      dh->next = head;
      while(head){
        length++; head = head->next;
      }
      head = dh->next;
      ListNode *pre, *cur, *nex;
      pre = dh;
      while(length >= k){
        cur = pre->next;
        nex = cur->next;
        for(int i = 0; i < k-1; i++){
          cur->next = nex->next;
          nex->next = pre->next;
          pre->next = nex;    // modifying the dummyhead pointer
          nex = cur->next;
        }
        pre = cur;
        length -= k;
      }
      return dh->next;
    }
};