/**
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */

var flat = function (arr, n) {
  const res = [];
  const flattening = (nums, l) => {
    for(const num of nums){
      if(Array.isArray(num) && l > 0)
        flattening(num, l - 1);
      else res.push(num);
    }
  }
  flattening(arr, n);
  return res;
};

// var flat = function (arr, n) {
//   if(n === 0) return arr;
//   const res = [];
//   for(const num of arr){
//     if(Array.isArray(num))
//       res.push(...flat(num, n - 1));
//     else res.push(num);
//   }
//   return res;
// };