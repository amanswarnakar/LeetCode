/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  int minSwaps(vector<int> &arr){
    int n = arr.size();
    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++){
      arrPos[i].first = arr[i];
      arrPos[i].second = i;
    }
    sort(arrPos, arrPos + n);
    vector<bool> vis(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++){
      if (vis[i] || arrPos[i].second == i)
        continue;
      int temp = 0;
      int j = i;
      while (!vis[j]){
        vis[j] = 1;
        j = arrPos[j].second;
        temp++;
      }
      if (temp > 0){
        ans += (temp - 1);
      }
    }
    return ans;
  }
  
  int minimumOperations(TreeNode* root) {
    queue<TreeNode *> q;
    q.emplace(root);
    int ans = 0;
    vector<int> temp;
    vector<int> v;
    while(!q.empty()){
      v.resize(0);
      int sz = q.size();
      for(int i = 0; i < sz; i++){
        auto node = q.front(); q.pop();
        v.emplace_back(node->val);
        if(node->left) q.emplace(node->left);
        if(node->right) q.emplace(node->right);
      }
      ans += minSwaps(v);
    }
    return ans;
  }
};