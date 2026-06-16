var createCounter = function(init: number) {
  let currentCount = init;

  function increment() {
    return ++currentCount;
  }

  function decrement() {
      return --currentCount;
  }

  function reset() {
      return (currentCount = init);
  }

  return { increment, decrement, reset };
};
