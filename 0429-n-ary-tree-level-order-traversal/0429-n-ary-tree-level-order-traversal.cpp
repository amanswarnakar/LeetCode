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
      // if(!root) return {};
      vector<vector<int>> ans;
      queue<Node *> q;
      if(root) q.emplace(root);
      while(!q.empty()){
        int sz = q.size();
        vector<int> temp;
        while(sz--){
          auto curr = q.front(); q.pop();
          temp.emplace_back(curr->val);
          for(auto &child: curr->children){
            q.emplace(child);
          }
        }
        ans.emplace_back(temp);
      }
      return ans;
    }
};