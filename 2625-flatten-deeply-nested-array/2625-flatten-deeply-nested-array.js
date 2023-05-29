/**
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */
var flat = function (arr, n) {
  if(n === 0) return arr;
  const res = [];
  for(const num of arr){
    if(Array.isArray(num))
      res.push(...flat(num, n - 1));
    else res.push(num);
  }
  return res;
};