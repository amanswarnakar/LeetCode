/**
 * @param {Function} fn
 */
function memoize(fn) {
  let mp = {};
  return function(...args) {
    const key = JSON.stringify(args);
    if(key in mp) return mp[key];
    const fnOutput = fn(...args);
    mp[key] = fnOutput;
    return fnOutput;
  }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */