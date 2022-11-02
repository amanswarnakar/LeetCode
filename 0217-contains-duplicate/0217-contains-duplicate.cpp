class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      // map<int, int> mp;
      // for(int i = 0; i < nums.size(); i++){
      //   mp[nums[i]]++;
      //   if(mp[nums[i]] > 1) return true;
      // }
      // return false;
      
      unordered_set<int> s;
      for(auto &num: nums){
        if(!s.insert(num).second) return true;
        // Set.insert() returns a pair in which 
        // the second part of the pair is a bool
        // value that indicates whether the element 
        // has been inserted into the set or not.
        // Returns true if inserted, false otherwise.
      }
      return false;
    }
};