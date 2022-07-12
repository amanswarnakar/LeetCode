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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      // Recursive Approach
      
//       if(l1 == nullptr)
//         return l2;
//       if(l2 == nullptr)
//         return l1;
      
//       if(l1->val < l2->val){
//         l1->next = mergeTwoLists(l1->next, l2);
//         return l1;
//       }
//       else{
//         l2->next = mergeTwoLists(l1, l2->next);
//         return l2;
//       }
//       return l1;
      
      // Iterative Approach
      
      if(l1 == nullptr) return l2;
      if(l2 == nullptr) return l1;
      if(l1->val > l2->val) std::swap(l1, l2);
      ListNode *res = l1;
      while(l1 != nullptr and l2 != nullptr){
        ListNode *temp(0);
        while(l1 != nullptr and l1->val <= l2->val){
          temp = l1;
          l1 = l1->next;
        }
        temp->next = l2;
        std::swap(l1, l2);
      }
      return res;
    }
};