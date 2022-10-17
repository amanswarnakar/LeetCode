class Solution {
public:
    bool checkIfPangram(string sentence) {
      vector<int> v(26, 0);
      for(char ch : sentence){
        v[ch - 'a']++;
      }
      sort(v.begin(), v.end());
      return v[0] != 0;
    }
};