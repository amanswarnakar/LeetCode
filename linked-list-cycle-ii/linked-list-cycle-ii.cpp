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
      // Two Pointer Approach
      
      ListNode *fast = head, *slow = head;
      bool flag = false;
      while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
          flag = true;
          break;
        }
      }
      if(!flag) return NULL;
      fast = head;
      while(fast != slow){
        fast = fast->next;
        slow = slow->next;
      }
      return slow;
      
      // HashSet Approach
      
      // unordered_set<ListNode *> st;
      // while(head and head->next){
      //   if(st.insert(head).second == false) return head;
      //   head = head->next;
      // }
      // return NULL;
    }
};