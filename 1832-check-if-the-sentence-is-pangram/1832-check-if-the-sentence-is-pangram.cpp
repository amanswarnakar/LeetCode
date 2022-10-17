class Solution {
public:
    bool checkIfPangram(string sentence) {
      vector<int> v(26, 0);
      for(char ch : sentence){
        v[ch - 'a']++;
      }
      // sort(v.begin(), v.end());
      // return v[0] != 0;
      int cnt = 0;
      for(int i = 0; i < 26; i++){
        if(v[i] > 0) cnt++;
      }
      return cnt == 26;
      
      // set<char> s;
      // for(char ch : sentence){
      //   s.insert(ch);
      // }
      // return s.size() == 26;
    }
};