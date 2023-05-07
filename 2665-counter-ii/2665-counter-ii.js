/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let val = init;
    const increment = () => {
      return ++val;
    }
    const reset = () => {
      val = init;
      return val;
    }
    const decrement = () => {
      return --val;
    }
    return {increment, reset, decrement};
};


/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */