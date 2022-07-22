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
  
    ListNode *reverseLinkedList(ListNode *head){
      ListNode *prev = nullptr, *nxt;
      while(head != nullptr){
        nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
      }
      return prev;
    }
  
    bool isPalindrome(ListNode* head) {
      // Storing elements in a array
      // vector<int> vec;
      // while(head){
      //   vec.push_back(head->val);
      //   head = head->next;
      // }
      // for(int i = 0; i < vec.size() / 2; i++){
      //   if(vec[i] != vec[vec.size() - 1 - i])
      //     return false;
      // }
      // return true;
      
      
      if(head == NULL or head->next == NULL) return true;
     
      ListNode *dH = new ListNode(0);   // dummyHead
      dH->next = head;
      ListNode *fast = dH->next;
      ListNode *slow = dH->next;
      
      while(fast->next and fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
      }
      
      slow->next = reverseLinkedList(slow->next);
      slow = slow->next;
      fast = dH->next;
      
      while(slow){
        if(slow->val != fast->val)
          return false;
        fast = fast->next;
        slow = slow->next;
      }
      return true;
    }
};