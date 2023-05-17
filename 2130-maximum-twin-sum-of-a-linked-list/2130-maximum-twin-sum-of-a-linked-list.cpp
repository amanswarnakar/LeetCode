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
    int pairSum(ListNode* head) {
      ListNode *dh = new ListNode(0);
      dh->next = head;
      stack<int> st;
      ListNode *fast = dh->next, *slow = dh->next;
      while(fast and fast->next){
        st.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
      }
      int ans = 0;
      while(slow){
        ans = max(ans, st.top() + slow->val);
        slow = slow->next;
        st.pop();
      }
      return ans;
    }
  
  /*
    int pairSum(ListNode* head) {
      vector<int> v;
      while(head){
        v.emplace_back(head->val);
        head = head->next;
      }
      int ans = 0, n = v.size();
      for(int i = 0; i < n / 2; i++){
        ans = max(ans, v[i] + v[n - 1 - i]);
      }
      return ans;
    }
  */
};