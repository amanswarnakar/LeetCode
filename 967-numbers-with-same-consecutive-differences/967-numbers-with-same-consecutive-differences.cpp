class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
      vector<int> ans = {1,2,3,4,5,6,7,8,9};
      for(int i = 2; i <= n; i++){
        vector<int> temp;
        for(auto i : ans){
          int ld = i % 10;
          if(k + ld < 10){
            temp.push_back(i * 10 + k + ld);
          } 
          if(ld - k >= 0 and k > 0){
            temp.push_back(i * 10 + ld - k);
          }
        }
        ans = temp;
      }
      return ans;
    }
};