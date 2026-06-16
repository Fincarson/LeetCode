class Counter {
  init: number;
  currentCount: number;
  constructor(init) {
    this.init = init;
    this.currentCount = init;
  }

  increment() {
    this.currentCount += 1;
    return this.currentCount;
  }

  decrement() {
    this.currentCount -= 1;
    return this.currentCount;
  }

  reset() {
    this.currentCount = this.init;
    return this.currentCount;
  }
}


var createCounter = function(init: number) {
  return new Counter(init);
};
