class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      vector<int> p(26), q(26);
      for(int i = 0; i < s1.size(); i++){
        p[s1[i] - 'a']++;
      }
      int n = s1.size(), l = 0, r = 0;
      while(r < s2.size()){
        q[s2[r] - 'a']++;
        if(r - l + 1 == n and p == q) return true;
        else if(r - l + 1 < n) r++;
        else {
          q[s2[l] - 'a']--; l++; r++;
        }
      }
      return false;
    }
};