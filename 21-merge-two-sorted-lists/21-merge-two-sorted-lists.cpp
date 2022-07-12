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
      // Recursive Approach  TC- O(n+m) SC- O(1)
      
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
      
      // Iterative Approach  TC- O(n+m) SC- O(1)
      
      // if(l1 == nullptr) return l2;
      // if(l2 == nullptr) return l1;
      // if(l1->val > l2->val) std::swap(l1, l2);
      // ListNode *res = l1;
      // while(l1 != nullptr and l2 != nullptr){
      //   ListNode *temp = nullptr;
      //   while(l1 != nullptr and l1->val <= l2->val){
      //     temp = l1;
      //     l1 = l1->next;
      //   }
      //   temp->next = l2;
      //   std::swap(l1, l2);
      // }
      // return res;
      
      
      // Extra Space Solution
      // TC- O(n+m) SC- O(n+m)
      if(l1 == nullptr) return l2;
      if(l2 == nullptr) return l1;   
      ListNode *ans = l1;
      if(l1->val > l2->val){
        ans = l2;
        l2 = l2->next;
      } else {
        l1 = l1->next;
      }
      ListNode *temp = ans;
      while(l1 != nullptr and l2 != nullptr){
        if(l1->val < l2->val){
          temp->next = l1;
          l1 = l1->next;
        } else {
          temp->next = l2;
          l2 = l2->next;
        }
        temp = temp->next;
      }
      if(l1 != nullptr)
        temp->next = l1;
      else 
        temp->next = l2;
      return ans;      
    }
};