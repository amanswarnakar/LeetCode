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
    ListNode *detectCycle(ListNode *head) {
      unordered_set<ListNode *> st;
      while(head and head->next){
        if(st.insert(head).second == false) return head;
        head = head->next;
      }
      return NULL;
    }
};