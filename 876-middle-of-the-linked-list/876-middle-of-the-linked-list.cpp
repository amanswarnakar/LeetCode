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
    ListNode* middleNode(ListNode* head) {
      ListNode *fast = head, *slow = head;
      while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
      }
      return slow;
      
      // int cnt = 0;
      // ListNode *node1 = head;
      // while(node1->next){
      //   node1 = node1->next;
      //   cnt++;
      // }
      // cnt = (cnt + 1) / 2;
      // ListNode *node2 = head;
      // while(cnt--){
      //   node2 = node2->next;
      // }
      // return node2;
    }
};