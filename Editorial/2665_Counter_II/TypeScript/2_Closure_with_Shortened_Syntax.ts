var createCounter = function(init: number) {
  let currentCount = init;
  return {
    increment: () => ++currentCount,
    decrement: () => --currentCount,
    reset: () => (currentCount = init),
  }
};
