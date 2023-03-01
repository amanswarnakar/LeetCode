class Solution {
public:
    void recur(vector<int> &v, vector<bool> &vis, vector<int> &temp, vector<vector<int>> &ans){
      if(temp.size() == v.size()){
        ans.emplace_back(temp);
        return;
      }
      for(int i = 0; i < v.size(); i++){
        if(!vis[i]){
          vis[i] = true;
          temp.emplace_back(v[i]);
          recur(v, vis, temp, ans);
          temp.pop_back();
          vis[i] = false;
        }
      }
    }
    vector<vector<int>> permute(vector<int>& v) {
      int n = v.size();
      vector<int> temp;
      vector<vector<int>> ans;
      vector<bool> vis(n, false);
      recur(v, vis, temp, ans);
      return ans;
    }
};