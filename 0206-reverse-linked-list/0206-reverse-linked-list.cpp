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
    ListNode* reverseList(ListNode* head) {
      // Iterative solution
      
//       ListNode *prev_p = NULL, *curr_p = head, *next_p;
//       while(curr_p){
//         next_p = curr_p->next;
//         curr_p->next = prev_p;
                
//         prev_p = curr_p;
//         curr_p = next_p;
//       }
//       head = prev_p;
//       return head;
      
      
      // Recursive Solution
      
      ListNode *prev = nullptr;
      while(head != nullptr){
        ListNode *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
      }
      return prev;
    }
};