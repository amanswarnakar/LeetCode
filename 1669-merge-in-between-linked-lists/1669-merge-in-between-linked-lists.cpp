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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
      ListNode *A = list1;
      ListNode *B = A;
      for(int i = 0; i < b + 1; i++){
        B = B->next;
        if(i < a - 1){
          A = A->next;
        }
      }
      A->next = list2;
      while(list2->next){
        list2 = list2->next;
      }
      list2->next = B;
      return list1;
    }
};