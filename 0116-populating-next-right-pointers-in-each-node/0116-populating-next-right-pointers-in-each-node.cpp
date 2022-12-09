/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
      if(!root) return root;
      queue<Node *> q;
      q.emplace(root);
      while(!q.empty()){
        Node *temp = NULL;
        int sz = q.size();
        for(int i = 0; i < sz; i++){
          auto qf = q.front(); q.pop();
          qf->next = temp;
          temp = qf;
          if(qf->right){
            q.emplace(qf->right);
            q.emplace(qf->left);
          }
        }
      }
      return root;
    }
};