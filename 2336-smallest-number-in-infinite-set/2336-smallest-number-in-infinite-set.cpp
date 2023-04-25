class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    map<int, int> mp;
    SmallestInfiniteSet() {
      for(int i = 1; i < 1002; i++){
        pq.push(i);
        mp[i]++; 
      }
    }
    
    int popSmallest() {
      int top = pq.top();
      mp[top]--;
      pq.pop();
      return top;
    }
    
    void addBack(int num) {
      if(mp[num] == 1) return;
      pq.push(num);
      mp[num]++;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */