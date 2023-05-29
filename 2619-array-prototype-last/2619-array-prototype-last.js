Array.prototype.last = function() {
  let sz = this.length;
  return sz === 0 ? -1 : this[sz - 1];
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */