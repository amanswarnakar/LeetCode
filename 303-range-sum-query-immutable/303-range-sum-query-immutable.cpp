class NumArray {
public:
    vector<int> sumarr;
    NumArray(vector<int>& nums) {
      for(int i = 0; i < nums.size(); i++){
        if(i == 0) sumarr.push_back(nums[i]);
        else sumarr.push_back(nums[i] + sumarr[i-1]);
      }
    }
    
    int sumRange(int left, int right) {
      if(left == 0) return sumarr[right];
      return sumarr[right] - sumarr[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */