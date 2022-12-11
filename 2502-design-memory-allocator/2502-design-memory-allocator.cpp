class Allocator {
public:
    vector<int> v;
    int sz;
  
    Allocator(int n) {
      v.resize(n, 0);
      sz = n;
    }
    
    int allocate(int size, int mID) {
      if(size > count(v.begin(), v.end(), 0)) return -1;
      int cnt = 0;
      bool flag = false;
      for(int i = 0; i < sz; i++){
        if(v[i] == 0){
          cnt++;
          if(cnt == size){
            flag = true; cnt = i;
          }
        } else {
          cnt = 0;
        }
        if(flag) break;
      } 
      if(flag)
        for(int i = cnt - size + 1; i <= cnt; i++){
          v[i] = mID;
        }
      return flag ? cnt - size + 1 : -1;
    }
    
    int free(int mID) {
      int res = 0;
      for(int i = 0; i < sz; i++){
        if(v[i] == mID) {
          v[i] = 0; res++;
        }
      }
      return res;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */