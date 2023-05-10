/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
  let sum = init;
  nums.forEach(e => {
    sum = fn(sum, e);
  })
  return sum;
};