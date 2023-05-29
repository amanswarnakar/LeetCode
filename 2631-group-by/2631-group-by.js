/**
 * @param {Function} fn
 * @return {Array}
 */
Array.prototype.groupBy = function(fn) {
  const res = {};
  for(const e of this){
    const key = fn(e);
    if(key in res) res[key].push(e);
    else res[key] = [e];
  }
  return res;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */