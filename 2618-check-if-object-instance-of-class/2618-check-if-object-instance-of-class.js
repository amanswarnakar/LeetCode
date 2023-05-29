/**
 * @param {any} obj
 * @param {any} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, cf) {
  if(obj === null || obj === undefined || typeof cf !== 'function')  
    return false;
  let proto = Object.getPrototypeOf(obj);
  while(proto !== null){
    if(proto === cf.prototype) return true;
    proto = Object.getPrototypeOf(proto);
  }
  return false;
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */