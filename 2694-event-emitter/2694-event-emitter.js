class EventEmitter {
  constructor() {
    this.events = {};
  }
  subscribe(e, cb) {
    this.events[e] = this.events[e] ?? [];
    this.events[e].push(cb);
    return {
      unsubscribe: () => {
        this.events[e] = this.events[e].filter(f => f !== cb);
        if(this.events[e].length === 0) delete this.events[e];
      },
    };
  }

  emit(e, args = []) {
    if(!(e in this.events)) return [];
    return this.events[e].map(f => f(...args));
  }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */