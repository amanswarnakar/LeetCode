class Solution {
public:
    int helper(vector<int> &freq){
      return (freq[0] + freq['e' - 'a'] + freq['i' - 'a'] + freq['o' - 'a'] + freq['u' - 'a']);
    }
    int maxVowels(string s, int k) {
      vector<int> freq(26, 0);
      int n = s.size(), ans = 0;
      for(int i = 0; i < n; i++){
        if(i < k) freq[s[i] - 'a']++;
        else {
          freq[s[i - k] - 'a']--;
          freq[s[i] - 'a']++;
        }
        ans = max(ans, helper(freq));
      }
      return ans;
    }
};