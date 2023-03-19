class Solution {
public:
    bool check(vector<int> &v, int x, int k){
      for(int i = 0; i < v.size(); i++){
        if(abs(v[i] - x) == k) return false;
      }
      return true;
    }
    int recur(int idx, vector<int> &v, vector<int> &temp, int k){
      int n = v.size();
      if(idx == n) return 0;
      int pick = 0, notPick = 0;
      if(check(temp, v[idx], k)){
        temp.emplace_back(v[idx]);
        pick = 1 + recur(idx + 1, v, temp, k);
        temp.pop_back();
      }
      notPick = recur(idx + 1, v, temp, k);
      return pick + notPick;
    }
    int beautifulSubsets(vector<int>& v, int k) {
      int n = v.size();
      vector<int> temp;
      return recur(0, v, temp, k);
    }
};