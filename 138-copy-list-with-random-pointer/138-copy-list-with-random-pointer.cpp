/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
      
      // HashMap Solution TC - O(2N)  SC - O(N)
      
      // map<Node*, Node*> mp;
      // Node *dh = new Node(0);
      // dh->next = head;
      // while(head){
      //   Node *temp = new Node(head->val);
      //   mp[head] = temp;
      //   head = head->next;
      // }
      // head = dh->next;
      // while(head){
      //   mp[head]->next = mp[head->next];
      //   mp[head]->random = mp[head->random];
      //   head = head->next;
      // }
      // return mp[dh->next];
      
      // Pointer Approach   TC - O(2N)  SC - O(1)
      
      Node *dh = new Node(0);
      dh->next = head;
      Node *iter = head;
      Node *front = head;
      while(iter != NULL){
        Node *temp = new Node(iter->val);
        front = iter->next;
        iter->next = temp;
        temp->next = front;
        iter = front;
      }
      iter = dh->next;
      while(iter != NULL){
        if(iter->random == NULL) iter->next->random = NULL;
        else iter->next->random = iter->random->next;
        iter = iter->next->next;        
      }
      Node *ans = new Node(0);
      Node *copy = ans;
      iter = dh->next;
      while(iter != NULL){
        front = iter->next->next;
        copy->next = iter->next;
        iter->next = front;
        iter = front;
        copy = copy->next;
      }
      return ans->next;
    }
};