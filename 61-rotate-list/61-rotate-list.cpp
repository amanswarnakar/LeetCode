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
    ListNode* rotateRight(ListNode* head, int k) {
      if(head == NULL or head->next == NULL) return head;
      
      ListNode *dh = new ListNode(0);
      dh->next = head;
      ListNode *fast = dh->next;
      ListNode *slow = dh->next;
      ListNode *temp = dh->next;
      int cnt = 0;

      while(temp){
        temp = temp->next;
        cnt++;
      }
      int val = (k % cnt);
      while(val-- > 0){
        if(fast->next)
          fast = fast->next;
        else fast = dh->next;
      }
      while(fast->next){
        slow = slow->next;
        fast = fast->next;
      }
      fast->next = head;
      temp = slow;
      slow = slow->next;
      temp->next = NULL;
      dh->next = slow;
      return dh->next;
    }
};