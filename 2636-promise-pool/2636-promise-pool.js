/**
 * @param {Function[]} functions
 * @param {number} n
 * @return {Function}
 */
var promisePool = async function(functions, n) {
  return new Promise((resolve, reject) => {
    let cnt = 0;
    let idx = 0;
    function helper(){
      if(idx >= functions.length){
        if(cnt === 0) resolve();
        return;
      }
      while(cnt < n && idx < functions.length){
        cnt++;
        const promise = functions[idx]();
        idx++;
        promise.then(() => {
          cnt--;
          helper();
        });
      }
    }
    helper();
  });
};

/**
 * const sleep = (t) => new Promise(res => setTimeout(res, t));
 * promisePool([() => sleep(500), () => sleep(400)], 1)
 *   .then(console.log) // After 900ms
 */