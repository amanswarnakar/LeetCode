/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function(arr, size) {
  var i = 0;
  const res = [];
  while(i < arr.length){
    const v = [];
    let cnt = size;
    while(cnt-- > 0 && i < arr.length){
      v.push(arr[i++]);
    }
    res.push(v);
  }
  return res;
};
