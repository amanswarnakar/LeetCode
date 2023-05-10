/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
  // let sum = init;
  nums.forEach(e => {
    init = fn(init, e);
  });
  // for(const e of nums){
  //   sum = fn(sum, e);
  // }
  return init;
};