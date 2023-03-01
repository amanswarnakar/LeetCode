class Solution {
public:
    void recur(int i, int t, vector<int> &v, vector<int> &temp, vector<vector<int>> &ans){
      if(t == 0){
        sort(temp.begin(), temp.end());
        ans.emplace_back(temp);
        return;
      }
      while(i < v.size() and t - v[i] >= 0){
        temp.emplace_back(v[i]);
        recur(i, t - v[i], v, temp, ans);
        i++;
        temp.pop_back();
      }
    }
    vector<vector<int>> combinationSum(vector<int>& v, int target) {
      vector<vector<int>> ans;
      vector<int> temp;
      sort(v.begin(), v.end());
      v.erase(unique(v.begin(),v.end()),v.end());
      recur(0, target, v, temp, ans);
      return ans;
    }
};