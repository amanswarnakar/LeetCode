/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
      vector<vector<int>> ans;
      if(!root) return ans;
      queue<Node *> q;
      q.push(root);
      while(!q.empty()){
        vector<int> temp;
        int n = q.size();
        for(int i = 0; i < n; i++){
          // auto it = q.front();
          temp.push_back(q.front()->val);
          for(auto x: q.front()->children){
            q.push(x);
          }
          q.pop();
        }
        ans.push_back(temp);
      }
      return ans;
    }
};