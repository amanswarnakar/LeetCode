class Solution {
public:
    int characterReplacement(string s, int k) {
      int l = 0, r = 0, maxi = INT_MIN, ans = INT_MIN, n = s.size();
      vector<int> freq(26, 0);
      while(r < n){
        freq[s[r] - 'A']++;
        maxi = max(maxi, freq[s[r] - 'A']);
        while(r - l + 1 - maxi > k){
          freq[s[l] - 'A']--; l++;
          maxi = *max_element(freq.begin(), freq.end());
        }
        ans = max(ans, r - l + 1);
        r++;
      }
      return ans;
    }
};