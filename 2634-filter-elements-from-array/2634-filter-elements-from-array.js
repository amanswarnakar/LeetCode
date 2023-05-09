/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
  const v = [];
  for(let i = 0; i < arr.length; i++){
    if(fn(arr[i], i)) v.push(arr[i]);
  }
  return v;
};