class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
      set<string> ans;
      vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
      for(string w : words){
        string s = "";
        for(int i = 0; i < w.size(); i++){
          s += morse[w[i] - 97];
        }
        ans.insert(s);
      }
      return ans.size();
    }
};