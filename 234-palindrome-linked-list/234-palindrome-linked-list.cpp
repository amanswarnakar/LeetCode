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
    bool isPalindrome(ListNode* head) {
      // Storing elements in a array
      vector<int> vec;
      while(head){
        vec.push_back(head->val);
        head = head->next;
      }
      for(int i = 0; i < vec.size() / 2; i++){
        if(vec[i] != vec[vec.size() - 1 - i])
          return false;
      }
      return true;
      
      
//       if(head == NULL or head->next == NULL) return true;
      
//       ListNode *dummyHead = new ListNode(0);
//       dummyHead->next = head;
//       ListNode *temp = new ListNode(0);
//       ListNode *fast = dummyHead->next;
//       ListNode *slow = dummyHead->next;
//       ListNode *prev = NULL, *nxt;
      
//       while(fast and fast->next){
//         nxt = slow->next;
//         slow->next = prev;
//         prev = slow;
//         slow = nxt;
        
//         fast = fast->next->next;
        
//       }
    }
};