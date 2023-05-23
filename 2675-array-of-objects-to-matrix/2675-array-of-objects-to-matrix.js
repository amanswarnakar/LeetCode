/**
 * @param {Array} arr
 * @return {Matrix}
 */
var jsonToMatrix = function(arr) {
  const isObject = x => (x !== null && typeof x === 'object');
  const getKeys = obj => {
    const isObject = x => (x !== null && typeof x === 'object');
    if(!isObject(obj)) return [''];
    const result = [];
    for(const key of Object.keys(obj)){
      const childKeys = getKeys(obj[key]);
      for(const childKey of childKeys){
        result.push(childKey ? `${key}.${childKey}` : key);
      }
    }
    return result;
  }  
  
  const keysSet = arr.reduce((acc, curr) => {
    getKeys(curr).forEach((k) => acc.add(k));
    return acc;
  }, new Set());
  
  const keys = Array.from(keysSet).sort();
  
  const getValue = (obj, path) => {
    const paths = path.split('.');
    let i = 0;
    let val = obj;
    while(i < paths.length){
      if(!isObject(val)) break;
      val = val[paths[i++]];
    }
    if(i < paths.length || isObject(val) || val === undefined) return '';
    return val;
  }
  const matrix = [keys];
  arr.forEach(obj => {
    matrix.push(keys.map(key => getValue(obj, key)));
  });
  return matrix;
};