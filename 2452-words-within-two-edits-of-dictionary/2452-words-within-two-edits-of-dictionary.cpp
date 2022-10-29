class Solution {
public:
    bool helper(string &a, string &b){
      int cnt = 0;
      for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i])
          cnt++;
      }
      return cnt <= 2;
    }
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
      vector<string> ans;
      for(auto &i: q){
        for(auto &j: d){
          if(helper(i, j)){
            ans.emplace_back(i); break;
          } 
        }
      }
      return ans;
    }
};