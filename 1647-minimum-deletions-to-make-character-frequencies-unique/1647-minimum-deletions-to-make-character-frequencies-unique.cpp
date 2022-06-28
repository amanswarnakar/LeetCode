class Solution {
public:
    int minDeletions(string s) {
      int n = s.length();
      vector<int> vec(26, 0);
      for(int i = 0; i < n; i++){
        vec[int(s[i]) - 97]++;
      }
      sort(vec.begin(), vec.end(), greater<int>());
      int l = 0, r = 1, ans = 0;
      while(r < 26){
        while(vec[l] <= vec[r]){
          vec[r]--; ans++;
        }
        if(vec[r] == 0){
          r++;
        } else {
          l++; r++;
        }
      }
      return ans;
    }
};