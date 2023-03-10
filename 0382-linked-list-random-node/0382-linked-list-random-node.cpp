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
    ListNode *head = NULL;
    int n = 0;
    Solution(ListNode* head) {
      this->head = head;
      while(head){
        this->n++;
        head = head->next;
      }
    }
    
    int getRandom() {
      int k = rand() % n;
      ListNode *p = this->head;
      while(k--){
        p = p->next;
      }
      return p->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */